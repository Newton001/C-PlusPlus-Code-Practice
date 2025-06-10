#include <iostream>

using namespace std;


// Odd Number Checker
void check_number(int & n)
{

    cout<<"Enter you number here"<<endl;
    cin>>n;

    if(n%2==0) cout<<"Number is Even"<<endl;
    else cout<<"Number is Odd"<<endl;

    cout << "Check is done!" << endl;
}


// Loop Sum adder
int add_num(int n){
    if (n==1) return n;
    else return n + add_num(n-1);
}

// BONUS: Multiplication table
void multiplication_table_print(const int &n)
{
    for (int var = 0; var <= n; ++var) {
        cout<< var <<" x " << n << " = "<< var * n<<endl;
    }
}

int main()
{
    int n;
    check_number(n);

    cout<< "Sum of the Numbers from 1 to n is: "<< add_num(n)<<endl;

    multiplication_table_print(n);

    return 0;
}
