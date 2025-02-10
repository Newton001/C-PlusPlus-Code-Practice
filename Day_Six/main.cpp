#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <cctype>

using namespace std;

// Trick no Loops

int main()
{
    std::cout<<"========================================================= Question 1 ======================================================"<<std::endl;

    // Container
    vector<char> alpha_list(std::views::iota('a','z'+1)|std::ranges::to<vector>());
    vector<char> alpha_list2;

    //Lets use Copy
    std::ranges::copy(std::views::iota('a','z'+1),back_inserter(alpha_list2));

    // Printing Out
    std::ranges::for_each(alpha_list,[](char c){std::cout<<c<<' ';});

    std::cout<<endl;

    std::ranges::for_each(alpha_list2,[](char c){std::cout<<c<<' ';});

    std::cout<<endl;


    std::cout<<"========================================================= Question 2 ======================================================"<<std::endl;

    ifstream my_car("cars.txt");
    vector<string> vector_car = std::ranges::istream_view<string>(my_car)|std::ranges::to<vector>();
    std::ranges::for_each(vector_car,[](const string& lst){std::cout<<lst<<std::endl;});


    std::cout<<"========================================================= Sorted ======================================================"<<std::endl;

    std::sort(vector_car.begin(),vector_car.end(), [](const string &a, const string &b){ return a<b; });
    std::ranges::for_each(vector_car,[](const string& lst){std::cout<<lst<<std::endl;});


    std::cout<<"========================================================= Print Out Using Copy  ======================================================"<<std::endl;
    std::ranges::copy(vector_car, std::ostream_iterator<string>(cout, "\n"));

    std::cout<<"========================================================= Question  3 Using Sets  ======================================================"<<std::endl;

    // **Reopen the file** before reading into `set<string>`
    my_car.clear();  // Reset stream state
    my_car.seekg(0); // Move file pointer back to the beginning

    set<string> set_car = std::ranges::istream_view<string>(my_car)|std::ranges::to<set>();
    std::ranges::copy(set_car, std::ostream_iterator<string>(cout,"\n"));

    std::cout<<"========================================================= Question 4 ======================================================"<<std::endl;

    for (auto it = vector_car.cbegin(); it !=vector_car.cend(); ++it)
    {
        if(!it->empty() && (*it)[0] == 'A')
        {
            cout<<*it<<"  ";
        }
    }
    cout<<endl;

    for(const auto& it : vector_car)
    {
        if(it[0] == 'A')
        {
            cout<<it<<"  ";
        }
    }

    std::cout<<"========================================================= Using Copy_if ======================================================"<<std::endl;
    std::ranges::copy_if(vector_car, std::ostream_iterator<string>(cout," "),[](const string &s){return!s.empty() && s[0]=='A';});
    cout<<endl;

    std::cout<<"========================================================= Question 5 ======================================================"<<std::endl;

    string allowed_letters = "ABC";

    std::ranges::copy_if(vector_car, std::ostream_iterator<string>(cout,"  "),
                         [&allowed_letters](const string&s){
                                return std::any_of(allowed_letters.begin(),allowed_letters.end(),
                                    [first_letter = std::toupper(s[0])](char c){
                                        return std::toupper(c)== first_letter;});});


}
