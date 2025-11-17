#include "Book.h"
#include <string>
using namespace std;

Book::Book(string t, string a, int p)
{
    // TODO: Implement constructor
    // Hint: Initialize all member variables
    title = t;
    author = a;
    pages = p;
}

string Book::getTitle()
{
    // TODO: Implement getter
    // Hint: Return the title member variable
    return title;
}

string Book::getAuthor()
{
    // TODO: Implement getter
    // Hint: Return the author member variable
    return author;
}

int Book::getPages()
{
    // TODO: Implement getter
    // Hint: Return the pages member variable
    return pages;
}

int Book::getTotalWords()
{
    // TODO: Implement this method
    // Hint: Multiply pages by 250
    return pages * 250;
}
