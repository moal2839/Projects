#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Book.h"
//#include "Book.cpp"
#include "User.h"
//#include "User.cpp"

using namespace std;

class Library
{
    private:
        int sizeBook = 50;
        int sizeUser = 100;
        Book books[50];
        User users[100];
        int numBooks;
        int numUsers;
        
    public:
       Library();
        int getSizeBook();
        int getSizeUser();
        int getNumBooks();
        int getNumUsers();
        int getRating(string userName, string title);
        int getCountReadBooks(string userName);
        void getRecommendations(string userName);
        int readBooks(string fileName);
        void printAllBooks();
        void printBooksByAuthor(string author);
        int readRatings(string fileName);
        void viewRatings(string userName, int minRating);
        double calcAvgRating(string title);
        double calcAvgRatingByAuthor(string author);
        int addUser(string userName);
        int checkOutBook(string userName, string title, int newRating);
};

#endif