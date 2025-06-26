#include <iostream>
#include<unordered_map>
#include <string>

using namespace std;


class Library{
private:
    unordered_map<string, string> isbn;
public:
    Library(const string &isbn_code, const string &title)
    {isbn[isbn_code] = title;}

    void add_book(const string &isbn_code, const string &title){
        isbn[isbn_code] = title;
    }

    void remove_book(const string &isbn_code){
        isbn.erase(isbn_code);
    }

    string get_book(const string &isbn_code) const{
        auto it = isbn.find(isbn_code);

        if(it!=isbn.end()){
            return it->second;
        }
        else
            return "Book not Found";
    }

    void display_all()const{
        for(const auto &pair:isbn){
            cout<<"ISBN: "<<pair.first<<" | Title "<<pair.second<< endl;
        }
    }
};

int main()
{
    Library lib("978-3-16-148410-0","C++ Primer");
    lib.add_book("978-0-13-110362-7", "The C Programming Language");
    cout<<lib.get_book("978-0-13-110362-7")<<endl;
    lib.remove_book("978-0-13-110362-7");
    lib.display_all();

    return 0;
}
