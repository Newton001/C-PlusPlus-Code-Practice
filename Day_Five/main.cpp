#include <iostream>
#include <utility>
#include <chrono>
#include <vector>
#include <tuple>
#include <string>
#include <map>

using namespace std;
/*
Given a positive integer n. Your task is to check if it is divisible as given below:
1. If it is divisible by 11, print "Eleven".
2. If it is divisible by 3, print "Three".
3. If it is divisible by 2, print "Two".
4. If not following the above three rules, print "-1".
Note: If n is divisible by more than one of the above-given numbers, print the one which is the largest.
*/


void isDivisibleByPrime(int n)
{
    if(n%11 == 0){
        std::cout<<"Eleven"<<std::endl;
    }
    else if(n%3 == 0){
        std::cout<<"Three"<<std::endl;
    }
    else if((n%2) == 0){
        std::cout<<"Two"<<std::endl;
    }
    else {
        std::cout<<"-1"<<std::endl;
    }
}

// Understanding C++ 17

std::pair<int, int> divide_remainder(int dividend, int divisor){

    return {dividend/divisor, dividend%divisor};
}

// Structured bindings also work withÂ std::tuple:
std::tuple<std::string, std::chrono::system_clock::time_point, unsigned> stock_infor(const std::string &name) {
    auto now = std::chrono::system_clock::now();  // Current time
    unsigned price = 150;  // Dummy stock price for example
    return {name, now, price};
}

struct employee {
    unsigned id;
    std::string name;
    std::string role;
    unsigned salary;
};




int main()
{
    // int t;
    // cin >> t;

    // while(t--){
    //     int n;
    //     cin >> n;

    //     isDivisibleByPrime(n);


    //     cout << "~" << "\n";
    // }

    std::cout<<"========================= Understanding C++ 17 ========================= "<<std::endl;

    auto [fraction, remainder]  = divide_remainder(16,3);
    std::cout<< "16/3 is "
              <<fraction << " with a remainder of "
              << remainder <<"\n\n";


    const auto [name, valid_time, price] = stock_infor("INTC");

    std::vector<employee> employees{
                                    {1, "Alice", "Manager", 75000},
                                    {2, "Bob", "Engineer", 60000},
                                    {3, "Charlie", "Technician", 45000},
                                    };

    for(const auto &[id, name, role, salary] : employees)
    {
        std::cout<<"Name: "<< name
                  <<"Role: "<< role
                  <<"Salary: "<<salary<<"\n\n";
    }

    std::map<std::string, size_t> animal_population {
                                                    {"humans",   7000000000},
                                                    {"chickens", 17863376000},
                                                    {"camels",   24246291},
                                                    {"sheep",
                                                     1086881528},
                                                    };

    for(const auto &[species, count]:animal_population) {
        std::cout<<"There are "<<count <<" "<<species
            <<" on this planet. \n";
    }
}
