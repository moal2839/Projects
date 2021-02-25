#ifndef USER_H
#define USER_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

class User
{
	private:
		string userName;
		int ratings[50];
		int numRatings;
		int size;

	public:
		string getUsername();
		int getRatingAt(int idx);
		int getNumRatings();
		int getSize();
		void setUsername(string name);
		bool setRatingAt(int idx, int value);
		void setNumRatings(int value);
		User();
		User(string name, int r[], int nR);
};

#endif