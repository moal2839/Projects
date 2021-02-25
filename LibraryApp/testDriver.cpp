#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Library.h"
//#include "Library.cpp"
#include "Book.h"
//#include "Book.cpp"
#include "User.h"
//#include "User.cpp"


using namespace std;

int main()
{
	//test
	//expected output 
	// 2
	// Here is a list of books
	// Title 1 by Author 1
	// Water by Author 2
	// Title 3 by Author 3
	// Title 4 by Author 1
	// WaterShip by Author 1
	// Title 5 by Author 3
	// Title 6 by Author 1
	// Title 7 by Author 2
	// Title 8 by Author 3
	// Fire by Author 1
	// Water by Author 2
	// Ice by Author 3
	// Magma by Author 1
	// lava by Author 1
	// Title 5 by Author 3
	// Title 6 by Author 1
	// Title 7 by Author 2
	// Title 8 by Author 3
	// Here is a list of books by Author 2
	// Water
	// Title 7
	// Water
	// Title 7
	// 0
	// 9
	// 5
	// Here are the books that Tom rated
	// Title : Water
	// Rating : 4
	// -----
	// Title : Title 3
	// Rating : 2
	// -----
	// Title : Title 4
	// Rating : 5
	// -----
	// Title : WaterShip
	// Rating : 3
	// -----
	// Title : Title 5
	// Rating : 2
	// -----
	// Title : Title 6
	// Rating : 4
	// -----
	// Title : Title 7
	// Rating : 3
	// -----
	// Title : Title 8
	// Rating : 5
	// -----
	// Here are the books that User2 rated
	// Title : Water
	// Rating : 5
	// -----
	// Title : Title 3
	// Rating : 3
	// -----
	// Title : WaterShip
	// Rating : 4
	// -----
	// Title : Title 5
	// Rating : 3
	// -----
	// Title : Title 7
	// Rating : 2
	// -----
	// 0
	// 3.4
	// 18
	// 2
	// 100
	// 1
	// 3
	// 1
	// There are no recommendations for Tom at present.
	
	Library myLibrary;
	int rv = myLibrary.readBooks("test.txt");
	cout << rv << endl;
	int r = myLibrary.readRatings("Ratings.txt");
	myLibrary.readBooks("test1.txt");
	cout << r << endl;
	myLibrary.printAllBooks();
	myLibrary.printBooksByAuthor("Author 2");
	cout << myLibrary.getRating("Tom", "Water") << endl;
	cout << myLibrary.getCountReadBooks("Tom") << endl;
	cout << myLibrary.getCountReadBooks("User2") << endl;
	myLibrary.viewRatings("Tom", 2);
	myLibrary.viewRatings("User2" , 2);
	cout << myLibrary.calcAvgRating("Water") << endl;
	cout << myLibrary.calcAvgRatingByAuthor("Author 1") << endl;
	cout << myLibrary.getNumBooks() << endl;
	cout << myLibrary.getNumUsers() << endl;
	cout << myLibrary.getSizeBook() << endl;
	cout << myLibrary.getSizeUser() << endl;
	int add = myLibrary.addUser("John");
	cout << add << endl;
	cout << myLibrary.getNumUsers() << endl;
	int checkOut = myLibrary.checkOutBook("John", "Ice", 3);
	cout << checkOut << endl;
	myLibrary.getRecommendations("Tom");
	
}