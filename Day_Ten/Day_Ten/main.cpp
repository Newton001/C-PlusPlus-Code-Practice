#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double user_average()
{
    int input;
    vector<double> my_vector;

    cout<<"Type in number of Values: ";
    cin>>input;
    cout<<endl;

    for(int i = 0; i<input;++i)
    {
        int val;
        cin>>val;
        my_vector.push_back(val);
    }

    double sum  = 0;

    for(auto &var:my_vector) sum +=var;

    if(input>0)
    {
        sum/=input;
        cout<<sum<<endl;
    }
    else
    {
        cout<<"No values to average"<<endl;
    }

    return sum;
}


void isPalidrome(string str) {
    string rev = str;

    reverse(rev.begin(), rev.end());

    if(str ==rev)
        cout<<"\""<<str
             <<"\" is Palindrome."<<endl;

    else
        cout<<"\"" <<str
             <<"\" is NOT palindrome."<<endl;
}


class Book{
public:
    string title, author, ISBN;

    Book(const string &title, const string &author, const string &ISBN) :
        title(title), author(author), ISBN(ISBN){}
};

void search_by_title(const std::vector<Book> &books, const string & search_title){
    bool found = false;

    for(const auto&book:books)
    {
        if(book.title==search_title){
            cout<<"Book found: \n";
            cout<<"Title: "<<book.title <<"\n";
            cout<<"Author: "<<book.author<<"\n";
            cout<<"ISBN: "<<book.ISBN<<"\n";
            found = true;
            break;
        }
    }
    if(!found) {
        cout<<"Book with Title \"" <<search_title <<"\" not found. \n";
    }
}



int main()
{
    vector<Book> library;

    library.emplace_back("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    library.emplace_back("1984", "George Orwell", "9780451524935");
    library.emplace_back("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    string query;

    cout<<"Enter title to search: ";

    getline(cin,query);

    search_by_title(library,query);

    cout << "The average is:"<<user_average()<< endl;
    isPalidrome("ABCDCBA");

    return 0;
}
