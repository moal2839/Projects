#include "Book.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

/**
 * Algorithm: gets the title of a Book object
 * 1: returns the title as a string
 *
 */ 

/**
 * function name getTitle(belongs to Book class)
 * takes no parameters
 * @return: returns the title of a Book object as a string
 *
 */ 

string Book::getTitle()
{
    return title;
}

/**
 * Algorithm: gets the author of a Book object
 * 1: returns the author as a string
 *
 */ 

/**
 * function name: getAuthor(belongs to Book class)
 * takes no parameters
 * @return: returns the author of a Book object as a string
 *
 */ 

string Book::getAuthor()
{
    return author;
}

/**
 * Algorithm: sets the title of a Book object
 * 1: takes a string parameter called t and sets title = t
 *
 */ 

/**
 * function name: setTitle(belongs to Book class)
 * @param: a string called t
 * @return: function doesn't return anything
 *
 */ 

void Book::setTitle(string t)
{
    title = t;
}

/**
 * Algorithm: sets the author of a Book object
 * 1: takes a string parameter called a and sets author = a
 *
 */ 

/**
 * function name: setAuthor(belongs to Book class)
 * @param: a string called a 
 * @return: function doesn't return anything
 *
 */ 

void Book::setAuthor(string a)
{
    author = a;
}

/**
 * default constructot for Book class
 * takes no parameters
 * sets the title and author to an empty string when a new Book object is declared with no parameters
 *
 */ 

Book::Book()
{
    title = "";
    author = "";
}

/**
 * parameterized constructor for Book class
 * takes two parameters a string called t and a string called a 
 * sets the title = t and author = a when a new Book object is declared with two string parameters
 *
 */ 

Book::Book(string t, string a)
{
    title = t;
    author = a;
}