// CS1300 Fall 2019
// Author: Mohammad Alaskar 
// Recitation: 203  
// project 2 - problem set 4.2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Library.h"
#include "User.h"
#include "Book.h"

using namespace std;

void displayMenu(){
    cout << "Select a numerical option:" << endl;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Read ratings" << endl;
    cout << "3. Print all books" << endl;
    cout << "4. Print books by author" << endl;
    cout << "5. Get rating" << endl;
    cout << "6. Find number of books user rated" << endl;
    cout << "7. View ratings" << endl;
    cout << "8. Get average rating" << endl;
    cout << "9. Get average rating by author" << endl;
    cout << "10. Add a user" << endl;
    cout << "11. Checkout a book" << endl;
    cout << "12. Get recommendations" << endl;
    cout << "13. Quit" << endl;
}

int main()
{
	bool quit = false;
	Library myLibrary;
	int choice;
	int nB;
	int nR;
	int rating;
	int countBooks;
	double avg;
	double avgByAuthor;
	int added;
	int valid;
	string bookFile;
	string userFile;
	string authorName;
	string userName;
	string title;
	int minRating;
	int newRating;
	
	
	while(quit == false)
	{
	    displayMenu();
	    cin >> choice;
	    
	    switch(choice)
	    {
	        case 1:
	            cout << "Enter a book file name: " << endl;
	            cin >> bookFile;
	            nB = myLibrary.readBooks(bookFile);
	            
	            if(nB == -2)
	            {
	                cout << "Database is already full. No books were added." << endl;
	            }
	            else if(nB == -1)
	            {
	                cout << "No books saved to the database." << endl;
	            }
	            else if(nB == 50)
	            {
	                cout << "Database is full. Some books may have not been added." << endl;
	            }
	            else
	            {
	                cout << "Total books in the database: " << myLibrary.getNumBooks() << endl;
	            }
	            cout << endl;
	            break;
	        case 2:
	            cout << "Enter a user file name: " << endl;
	            cin >> userFile;    
	            nR = myLibrary.readRatings(userFile);
	            
	            if(nR == -2)
	            {
	                cout << "Database is already full. No users were added." << endl;
	            }
	            else if(nR == -1)
	            {
	                cout << "No users saved to the database." << endl;
	            }
	            else if(nR == 100)
	            {
	                cout << "Database is full. Some users may have not been added." << endl;
	            }
	            else
	            {
	                cout << "Total users in the database: " << myLibrary.getNumUsers() << endl;
	            }
	            cout << endl;
	            break;
	        case 3:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                myLibrary.printAllBooks();
	            }
	            cout << endl;
	            break;
	        case 4:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter an author name: " << endl;
	                cin.ignore();
	                getline(cin, authorName);
	                myLibrary.printBooksByAuthor(authorName);
	            }
	            cout << endl;
	            break;
	        case 5:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a user name: " << endl;
	                cin.ignore();
	                getline(cin, userName);
	                cout << "Enter a book title: " << endl;
	                getline(cin, title);
	                rating = myLibrary.getRating(userName, title);
	                
	                if(rating == -3)
	                {
	                    cout << userName << " or " << title << " does not exist." << endl;
	                }
	                else if(rating == 0)
	                {
	                    cout << userName << " has not rated " << title << endl;
	                }
	                else
	                {
	                    cout << userName << " rated " << title << " with " << rating << endl;
	                }
	                
	            }
	            cout << endl;
	            break;
	        case 6:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a user name: " << endl;
	                cin.ignore();
	                getline(cin, userName);
	                countBooks = myLibrary.getCountReadBooks(userName);
	                
	                if(countBooks == -3)
	                {
	                    cout << userName << " does not exist." << endl;
	                }
	                else if(countBooks == 0)
	                {
	                    cout << userName << " has not rated any books." << endl;
	                }
	                else
	                {
	                    cout << userName << " rated " << countBooks << " books." << endl;    
	                }
	                
	            }
	            cout << endl;
	            break;
	        case 7:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a user name: " << endl;
	                cin.ignore();
	                getline(cin, userName);
	                cout << "Enter a minimum rating: " << endl;
	                cin >> minRating;
	                myLibrary.viewRatings(userName, minRating);
	            }
	            cout << endl;
	            break;
	        case 8:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a book title: " << endl;
	                cin.ignore();
	                getline(cin, title);
	                avg = myLibrary.calcAvgRating(title);
	                
	                if(avg == -3)
	                {
	                    cout << title << " does not exist." << endl;
	                }
	                else
	                {
	                    cout << "The average rating for " << title << " is " << avg << endl;
	                }
	                
	            }
	            cout << endl;
	            break;
	        case 9:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter an author name: " << endl;
	                cin.ignore();
	                getline(cin, authorName);
	                avgByAuthor = myLibrary.calcAvgRatingByAuthor(authorName);
	                
	                if(avgByAuthor == -3)
	                {
	                    cout << authorName << " does not exist." << endl;
	                }
	                else
	                {
	                    cout << "The average rating by " << authorName << " is " << avgByAuthor << endl;
	                }
	                
	            }
	            cout << endl;
	            break;
	        case 10:
	            cout << "Enter a user name: " << endl;
	            cin.ignore();
	            getline(cin, userName);
	            added = myLibrary.addUser(userName);
	            
	            if(added == -2)
	            {
	                cout << "Database is already full. " << userName << " was not added." << endl;
	            }
	            else if(added == 0)
	            {
	                cout << userName << " already exists in the database." << endl;
	            }
	            else
	            {
	                cout << "Welcome to the library " << userName << endl;
	            }
	            cout << endl;
	            break;
	        case 11:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a user name: " << endl;
	                cin.ignore();
	                getline(cin, userName);
	                cout << "Enter a book title: " << endl;
	                getline(cin, title);
	                cout << "Enter a new rating: " << endl;
	                cin >> newRating;
	                valid = myLibrary.checkOutBook(userName, title, newRating);
	                
	                if(valid == -4)
	                {
	                    cout << newRating << " is not valid." << endl;
	                }
	                else if(valid == -3)
	                {
	                    cout << userName << " or " << title << " does not exist." << endl;
	                }
	                else
	                {
	                    cout << "We hope you enjoyed your book. The rating has been updated." << endl;
	                }
	                
	            }
	            cout << endl;
	            break;
	        case 12:
	            if( (myLibrary.getNumBooks() == 0) || (myLibrary.getNumUsers() == 0))
	            {
	                cout << "Database has not been fully initialized." << endl;
	            }
	            else
	            {
	                cout << "Enter a user name: " << endl;
	                cin.ignore();
	                getline(cin, userName);
	                myLibrary.getRecommendations(userName);
	            }
	            cout << endl;
	            break;
	        case 13: 
	            cout << "Good bye!" << endl;
	            quit = true;
	            break;
	        default:
	            cout << "Invalid input." << endl;
	            cout << endl;
	            break;
	    }
	}
}