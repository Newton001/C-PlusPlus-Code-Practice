#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <string>
#include <fstream>


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

    ostream my_car;
    my_car.open("cars.txt");
    vector<string>




}
