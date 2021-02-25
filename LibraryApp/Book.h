#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class Book
{
  private:
  string title;
  string author;
  
  public:
  string getTitle();
  string getAuthor();
  void setTitle(string t);
  void setAuthor(string a);
  Book();
  Book(string t, string a);
};

#endif