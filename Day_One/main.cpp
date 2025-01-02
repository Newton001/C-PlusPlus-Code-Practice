#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//String Reversal
string reverseString(string str)
{
    size_t n = str.length();
    for(size_t i = 0; i<n/2; ++i)
    {
        swap(str[i], str[n-i-1]);
    }
    return str;
}

// Palindrome Check
bool isPalindrome(string str)
{
    size_t left = 0;
    size_t right = str.length()-1;

    while(left<right) {
        if(str[left]!=str[right])
        {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

// Anagram Check
bool isAnagram(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;

}

// Fibonacci Check Recursive

size_t fibonacci(size_t n)
{
     // If n is zero or one, return the number itself
    if(n<=1)
        return n;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

// Fibonacci Iterative
size_t fibonacci_iterative(size_t n)
{
    size_t i, nT, t1=0, t2=1;
    for(i = 1; i<=n; ++i)
    {
        cout<<t1<< " ";
        nT = t1 + t2;
        t1=t2;
        t2 = nT;
    }

    return nT;
}


int main()
{
    string s = "Hello Newton";
    cout<<"Reversed String: "<<reverseString(s)<<endl;

    //====================== Palindrome Testing ==========================//
    string s1 = "radar";
    cout << "Is Palindrome: " << (isPalindrome(s1) ? "Yes" : "No") << endl;

    //====================== Anagram Testing =============================//

    string str1 = "listen";
    string str2 = "silent";

    cout<< "Is Anagram: " << (isAnagram(str1,str2) ? "Yes" : "No" )<< endl;

    //======================= Fibonacii Testing ==========================//
    size_t terms = 10;
    cout<< "Fibonacci number at position 10 is: " << fibonacci(terms);
    cout << endl;

    cout<< "The Numbers are " << fibonacci_iterative(terms);
    cout << endl;



}
