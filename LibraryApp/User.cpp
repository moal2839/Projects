#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "User.h"

using namespace std;


/**
 * function name: getUsername(belongs to User class)
 * @return: userName as a string 
 */ 

string User::getUsername()
{
	return userName;
}

/**
 * Algorithm: gets the rating at a certain index
 * 1: checks if the index is greater than or equal to 50 or if the index is less than 0, if so then return -1
 * 2: else it returns the ratings at the given index
 */
 

int User::getRatingAt(int idx)
{
	if ((idx >= 50) || (idx < 0))
	{
		return -1;
	}
	else
	{
		return ratings[idx];
	}
}

/**
 * function name: getNumRatings(belongs to User class)
 * @return: returns the number of ratings as an integer
 */

int User::getNumRatings()
{
	return numRatings;
}

/**
 * function name: getSize(belongs to User class)
 * @return: returns the size as an integer
 */ 

int User::getSize()
{
	return size;
}

/**
 * Algorithm: sets the username of a user object to the given name
 * 1: userName = given name
 */

void User::setUsername(string name)
{
	userName = name;
}

/**
 * Algorithm: sets the rating at a certain index of a user object with the given value and returns true if they updated correctly and false if they updated incorrectly
 * 1: checks if the index is greater than or equal 0 and less than 50 and if the value is greater than or equal 0 and less than or equal 5, then sets the ratings at that index with the given value and returns true.
 * 2: else returns false
 */

bool User::setRatingAt(int idx, int value)
{
	bool update;

	if (((idx >= 0) && (idx < 50)) && ((value >= 0) && (value <= 5)))
	{
		ratings[idx] = value;
		update = true;
	}
	else
	{
		update = false;
	}

	return update;
}

/**
 * Algorithm: sets the number of ratings of a User object with a given value
 * 1: numRatings = given value
 */ 

void User::setNumRatings(int value)
{
	numRatings = value;
}

/**
 * default constructor
 * no parameters taken
 * sets the userName to an empty string 
 * sets the size = 50
 * sets numRatings = 0
 * sets every element in the ratings array to 0
 */ 

User::User()
{
	int i;
	userName = "";
	size = 50;
	numRatings = 0;

	for (i = 0; i < 50; i++)
	{
		ratings[i] = 0;
	}
}

/**
 * parameterized constructor
 * takes three parameters a string name and an integer array called r for ratings, and an integer nR for numRatings
 * checks if numRatings is less than or equal 50 then
 *	sets userName = name
 *	sets numRatings = nR
 *	sets i = 0 
 *	for every i till 50 then
 *		checks if i is less nR then
 *			sets ratings with index i = r with index i
 *		end if
 *		else
 *			sets ratings with index i = 0
 * end for
 */ 

User::User(string name, int r[], int nR)
{
	if (numRatings <= 50)
	{
		userName = name;
		numRatings = nR;

		int i;

		for (i = 0; i < 50; i++)
		{
			if (i < nR)
			{
				ratings[i] = r[i];
			}
			else
			{
				ratings[i] = 0;
			}
		}
	}
}