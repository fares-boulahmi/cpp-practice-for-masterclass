#ifndef Book_H
#define Book_H
#include <string>
using namespace std;

class Book
{
private:
    string title;
    string author;
    int pages;

public:
    Book(string t, string a, int p);
    string getTitle();
    string getAuthor();
    int getPages();
    int getTotalWords();
};

#endif