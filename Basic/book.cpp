#include <iostream>
using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    bool borrowed;

public:
    Book()
    {
        id = 0;
        title = "Unknown";
        author = "Unknown";
        borrowed = false;
    }
    Book(int id,
         string title,
         string author,
         bool borrowed) : id(id), title(title), author(author), borrowed(borrowed)
    {
    }
    string getTitle()
    {
        return title;
    }
    void setTitle(string title)
    {
        this->title = title;
    }

    void printInfo()
    {
        cout << id << " " << title << " " << author << endl;
    }
};

int main()
{
    Book b1 = Book();
    Book b2 = Book(12, "CPP Langauge", "James Author", true);

    b1.printInfo();
    b2.getTitle();
    b2.printInfo();
}