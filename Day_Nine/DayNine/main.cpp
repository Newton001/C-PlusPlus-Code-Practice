#include <iostream>
#include <vector>
#include <algorithm>
#include <ostream>
#include <iterator>

using namespace std;

void array_reverse(vector<int> &array)
{
    int n = array.size();

    vector<int> temp(n);

    for(int i=0; i<n; ++i)
    {
        temp[i] = array[n-i-1];
    }
    for (int var = 0; var < n; ++var) {
        array[var] = temp[var];
    }
}

float calculator()
{
    int num1, num2;

    char op;

    std::cout<<" Enter the first Number: ";
    std::cin>>num1;

    std::cout<<" Enter the second Number: ";
    std::cin>>num2;

    std::cout<< "Enter the operation ( +, -, *, /): ";
    std::cin>>op;

    float result;

    if(op =='+'){
        result = num1 + num2;
    } else if(op == '-'){
        result = num1 - num2;
    } else if(op == '*'){
        result = num1 * num2;
    } else if(op == '/'){
        if(num2 !=0)
            result = static_cast<float>(num1/num2);
        else{
            std::cout<<"Error! Cannot divide by Zero"<<std::endl;
            return -1;
        }
    }else{
        std::cout<<" Invalid Operator" <<std::endl;
        return -1;
    }

    return result;
}

int factorial(int n)
{
    if (n <=1) return 1;
    return n * factorial(n-1);
}

int main()
{
    vector<int> arr = { 1, 4, 3, 2, 6, 5 };

    array_reverse(arr);
    for_each(arr.cbegin(), arr.cend(),[](const int& n) { std::cout << n << ' '; });

    std::cout << std::endl;

    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<" "<<std::endl;

    std::cout<<factorial(5)<< std::endl;

    std::cout<<calculator()<<std::endl;

    return 0;
}
