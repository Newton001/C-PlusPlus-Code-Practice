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

int factorial(int n)
{
    if (n < 2) return n;
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

    return 0;
}
