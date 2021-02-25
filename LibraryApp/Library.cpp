// CS1300 Fall 2019
// Author: Mohammad Alaskar 
// Recitation: 203  
// project 2 - problem set 4.1 

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "Library.h"
#include "Book.h"
//#include "Book.cpp"
#include "User.h"
//#include "User.cpp"


using namespace std;

/**
 * Default constructor for the library class
 * takes no parameters
 * sets the number of Users(numUsers) and number of Books(numBooks) to 0
 *
 */ 

Library::Library()
{
    numBooks = 0;
    numUsers = 0;
}

/**
 * function name: getSizeBook(belongs to library class)
 * no parameters taken
 * @return: returns the sizeBook
 *
 */ 

int Library::getSizeBook()
{
    return sizeBook;
}

/**
 * function name: getSizeUser(belongs to library class)
 * no parameters taken
 * @return: returns the sizeUser
 *
 */ 

int Library::getSizeUser()
{
    return sizeUser;
}

/**
 * function name: getNumBooks(belongs to library class)
 * no parameters taken
 * @return: returns the number of books currently stored 
 *
 */ 

int Library::getNumBooks()
{
    return numBooks;
}

/**
 * function name: getNumUsers(belongs to library class)
 * no parameters taken
 * @return: returns the number of users currently stored
 *
 */ 

int Library::getNumUsers()
{
    return numUsers;
}

/**
 * Algorithm: splits the sentences in to pieces separated by the delimeter
 * 1: if the sentence is empty then returns 0
 * 2: set i = 0
 * 3: set j = 0
 * 4: set  split count = 1
 * 5: set counter = 1
 * 6: set first position = 0
 * 7: for every i till sentence length then
 * 8:   if the (character in sentence with position i is not equal to the delimeter AND the position of the character before is equal to the delimeter)  OR (character in sentence with position i AND i is equal to 0) then
 * 9:       first position = i
 * 10:  end if
 * 11:  else if (character in sentence with position i is equal to the delimeter AND the character before is not equal to the delimeter) AND (i is not equal 0) AND (i is not equal to the sentence length -1) then
 * 12:      words[j] = the substring of sentence from first position and going a number of characters equal to counter
 * 13:      j = j + 1
 * 14:      first position = 0
 * 15:      counter = 1
 * 16:      split count = count + 1
 * 17:  end else if
 * 18:  else if the character in sentence with position i is not equal to the delimeter then
 * 19:      counter = counter + 1
 * 20:  end else if
 * 21: end for
 * 22: words[j] = the substring of sentence from first position and going a number of characters equal to counter
 * 23: if count is greater than the length of the word array then
 * 24:      return -1
 * 25: end if
 * 26: return count
 *
 */

 /**
  * Function name: split
  * @param1: a string called sentence
  * @param2: a character called deli
  * @param3: a string array called words
  * @param4: an integer called len
  * @return : returns an integer which is how many times the sentence was split
  *
  */

int split(string sentence, char deli, string words[], int len)
{
    int count = 1;
    int i;
    int j = 0;
    int counter = 1;
    int pos_first = 0;
    
    if(sentence == "") // checks if the sentence is empty then returns 0 if it is
    {
        return 0;
    }
    else
    {
        for(i = 0; i < sentence.length(); i++)
        {
            
            if( ( (sentence[i] != deli) && (sentence[i - 1] == deli) ) || ( (sentence[i] != deli) && (i == 0) ) ) // checks if the (character in sentence with position i is not equal to the delimeter AND the position of the character before is equal to the delimeter)  OR (character in sentence with position i AND i is equal to 0) then pos_first = i
            {
                pos_first = i;
            }
            else if( (sentence[i] == deli) && (sentence[i - 1] != deli) && (i != 0) && (i != (sentence.length() - 1)) ) // checks if (character in sentence with position i is equal to the delimeter AND the character before is not equal to the delimeter) AND (i is not equal 0) AND (i is not equal to the sentence length -1) 
            {
                words[j] = sentence.substr(pos_first, counter); // populates the words array with the substring of sentence from first position and going a number of characters equal to counter 
                j++;
                pos_first = 0; // resets pos_first
                counter = 1; // resets counter
                count++; 
            }
            else if(sentence[i] != deli) // checks if the character in sentence with position i is not equal to the delimeter
            {
                counter++;
            }
        }
        
        words[j] = sentence.substr(pos_first, counter); // populates the words array with the last word in the sentence that is separated with a delimeter
        
        return count;
    }
    

}

/**
 * Algorithm: checks if two words are the same (not case senesitive)
 * set i = 0
 * set newUserName = to empty string
 * set newName = to empty string 
 * for every i till userName's length then 
 *  changes the letter with position i in userName to uppercase and adds it to newUsername
 * end for
 * set i = 0
 * for every i till name's length then
 *  changes the letter with position i in name to uppercase and adds it to newName
 * end for
 * checks if newUserName and newName are equal if they are returns true
 * else it returns false
 */ 


bool checkIfSame(string userName, string name)
{
    bool isSame;
    int i;
    string newUserName = "";
    string newName = "";
    
    for(i = 0; i < userName.length(); i++) // changes all the letters of userName to upper case
    {
        newUserName += toupper(userName[i]);
    }
    
    for(i = 0; i < name.length(); i++) //changes all the letters of name to upper case 
    {
        newName += toupper(name[i]);
    }
    
    if(newUserName == newName) //checks if the newUserName is equal to the newName, if so returns true, else false
    {
        isSame = true;
    }
    else
    {
        isSame = false;
    }
    
    return isSame;
}

/**
 * Algorithm: return the number of books read
 * 1: checks if the number of books stored are equal to the size of the array, if it is then returns -2
 * 2: checks if the file doesn't exist, if so returns -1
 * 3: set j = numBooks
 * 4: while the authors of the array of books with position j and the titles of the array of books with poistion j are not empty then
 * 5:   j increments by one
 * 6: end while
 * 7: gets information from the file line by line and stores each line in a temporary string called authors_And_Titles
 * 8: if the line is not empty then
 * 9:   uses the split function to seperate the line into author and title
 * 10:  sets the author of the array of books with position j to authors_And_Title[0]
 * 11:  sets the title of the array of books with position j to authors_And_Title[1]
 * 12:  j increments by one
 * 13:loops from step 7 until it has looked at every line from that file
 * 14:returns numBooks
 *
 */ 

int Library::readBooks(string fileName)
{
    ifstream in_file;
    in_file.open(fileName);
    string line;
    int i ;
    int j = numBooks;
    string authors_And_Titles[50];
    
    if(numBooks == sizeBook)  // checks if the number of books stored are equal to the size of the array, if so returns -2
    {
        return -2;
    }
    else if(in_file.fail()) // checks if the file doesn't exist, if so then returns -1
    {
        return -1;
    }
    else
    {
        while( (books[j].getAuthor() != "") && (books[j].getTitle() != "")) //keeps looping until the author and title of the array of books with position j are empty
        {
            j++;
        }
        
        while(getline(in_file, line) && numBooks < 50) 
        {
            if(line != "") // checks if the line is not empty
            {
                string authors_And_Titles[2];
                split(line, ',', authors_And_Titles, 2);
                books[j].setAuthor(authors_And_Titles[0]);
                books[j].setTitle(authors_And_Titles[1]);
                j++;
                numBooks++;
            }
        }
        
        return numBooks;
    }
    
}

/**
 * Algorithm: prints all titles of books by their corresponding author
 * 1: checks if the number of books is less than or equal to 0,if so then it prints "No books are stored"
 * 2: else 
 * 3:   prints "Here is a list of books"
 * 4:   set i = 0 
 * 5:   for every i till number of Books then
 * 6:       print title from array of books with position [i] " by " author from array of books with position [i]
 * 7:   end for
 *
 */

void Library::printAllBooks()
{
    int i = 0;
    
    if(numBooks <= 0) // checks if the number of books is less than or equal 0, if so prints "No books are stored"
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        
        for(i = 0; i < numBooks; i++)
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
    
}

/**
 * Algorithm: prints all the book titles by the author's name
 * 1: checks if the number of books is less than or equal to 0,if so then it prints "No books are stored"
 * 2: else
 * 3:   set i = 0
 * 4:   set counter = 0
 * 5:  
 * 6:   set are_There_Books = false
 * 7:   for every i till the number of books then
 * 8:       if the authors of the array of books with position with position i is equal to the authors name then
 * 9:            pos[counter] = i
 * 10:           counter increments by one
 * 11:      end if
 * 12:  end for
 * 13:  set i = 0
 * 14:  for every i till counter then 
 * 15:      if titles in the array of books with position pos[i] is not empty then
 * 16:          are_There_Books = true
 * 17:          break out of the loop
 * 18:      end if
 * 19:      else if titles in the array of books with position pos[i] is empty then 
 * 20:          are_There_Books = false
 * 21:      end else if
 * 22:  end for
 * 23:  if are_There_Books is true and counter is greater than or equal 1 then
 * 24:      print "Here is a list of books by " authors name
 * 25:      set i = 0
 * 26:      for every i till counter then
 * 27:          if the titles in the array of books with position pos[i] is not empty
 * 28:              print the titles in the array of books with position pos[i] 
 * 29:          end if 
 * 30:      end for
 * 31:  end if 
 * 32:  else if are_There_Books is false then
 * 33:      print "There are no books by " authors name
 * 34:  end else if
 *
 */

void Library::printBooksByAuthor(string author)
{
    int counter = 0;
    int i;
    int pos[numBooks];
    bool are_There_Books = false;
    
    if(numBooks <= 0) // checks if the number of books is less than or equal to 0,if so then it prints "No books are stored"
    {
        cout << "No books are stored" << endl;
    }
    else
    {
            
        for(i = 0; i < numBooks; i++)
        {
            if(books[i].getAuthor() == author) // if the authors in the array of books with position i is equal to the authors name 
            {
                pos[counter] = i;
                counter++;
            }
        }
        
        for(i = 0; i < counter; i++)
        {
            if(books[pos[i]].getTitle() != "") // checks the titles in the array of books with position pos[i] is not empty
            {
                are_There_Books = true;
                break;
            }
            else if(books[pos[i]].getTitle() == "") // checks the titles in the array of books with position pos[i] is empty
            {
                are_There_Books = false;
            }
        }
        
        if( (are_There_Books == true) && (counter >= 1) ) // checks if there are books and counter is greater than of equal 1
        {
            cout << "Here is a list of books by " << author << endl;
            
            for(i = 0; i < counter; i++)
            {
                 if(books[pos[i]].getTitle() != "")
                 {
                     cout << books[pos[i]].getTitle() << endl;
                 }
            }
        }
        else if(are_There_Books == false) // checks if there are no books, if so then prints "There are no books by" authors name
        {
            cout << "There are no books by " << author << endl;
        }
    }
}

/**
 * Algorithm: finds the rating that ceratin uuser gave to a certain title
 * 1: set isThereUser = false
 * 2: set isThereTitle = false
 * 3: set i = 0
 * 4: for every i till the number of users then
 * 5:   if by using the checkIfSame function the username of the user object with index i is = to the given username then
 * 6:       set posUser = i and isThereUser = true
 * 7:   end if
 * 8: end for
 * 9: for every i till the number of books then
 * 10:   if by using the checkIfSame function the title of the book object with index i is = to the given title then
 * 11:       set posTitle = i and isThereTitle = true
 * 12:   end if
 * 13: end for
 * 14: checks if isThereUser or IsThereTitle are false or if the number of users or number of books are false, if so returns -3
 * 15: else returns the rating with index posTitle of the user object with index posUser
 */

int Library::getRating(string userName, string title)
{
    int posUser;
    int posTitle;
    int rating;
    bool isThereUser = false;
    bool isThereTitle = false;
    int i;
    
    for(i = 0; i < numUsers; i++) // finds the position where the userName of the user object is equal to the given userName
    {
        if(checkIfSame(users[i].getUsername(), userName) == true)
        {
            posUser = i;
            isThereUser = true;
        }
    }
    
     for(i = 0; i < numBooks; i++) // finds the position where the title of the book object is equal to the given title
    {
        if(checkIfSame(books[i].getTitle(), title) == true)
        {
            posTitle = i;
            isThereTitle = true;
        }
    }
    
    if( ((isThereUser == false) || (isThereTitle == false)) || ((numUsers == 0) || (numBooks == 0)) ) // checks if isThereUser or IsThereTitle are false or if the number of users or number of books are false, if so returns -3
    {
        return -3;
    }
    else
    {
        rating = users[posUser].getRatingAt(posTitle);
        return rating;  // returns the rating with index posTitle of the user object with index posUser
    }
}

/**
 * Algorithm: gets how many books were rated by a certain user
 * 1: set i = 0
 * 2: set rating counter = 0
 * 3: set isThereUser = false
 * 4: for every i till the number of users then
 * 5:   if by using the checkIfSame function the username of the user object with index i is = to the given username then
 * 6:       set posUser = i and isThereUser = true
 * 7:   end if
 * 8: end for
 * 9: checks if the isThereUser is equal to false or if the number of books is equal to 0, if so returns -3
 * 10: else
 * 11:  for every i till the number of books then
 * 12:      if the rating with index i for the user object with index posUser is not equal to 0 then
 * 13:          rating counter increments by one
 * 14:      end if
 * 15:  end for
 * 16: returns the rating counter
 */ 

int Library::getCountReadBooks(string userName)
{
    int i;
    int ratingCounter = 0;
    int posUser;
    bool isThereUser = false;
    
    for(i = 0; i < numUsers; i++) // finds the position where the userName of the user object is equal to the given userName
    {
        if(checkIfSame(users[i].getUsername(), userName) == true)
        {
            posUser = i;
            isThereUser = true;
        }
    }
    
    if( (isThereUser == false) || (numBooks == 0) ) // checks if isThereUser is false or if the numBooks is equal to 0, if so returns -3
    {
        return -3;
    }
    else
    {
        for(i = 0; i < numBooks; i++)
        {
            if(users[posUser].getRatingAt(i) != 0) // checks if the rating with index i for the user object with index posUser is not equal to 0, if so increments ratingCounter by one
            {
                ratingCounter++;
            }
        }
    
        
        return ratingCounter;
    }
    
}

/**
 * Algorithm: finds the number of users 
 * 1: set i = 0 
 * 2: set j = to the number of users stored
 * 3: checks if the number of users stored are equal to the user array size, if so returns -2
 * 4: checks if the file doesn't exist, if so returns -1
 * 5: else
 * 6:	while the username of the users object at index j is not empty then
 * 7:		j and the number of users stored increment by one
 * 8:	end while
 * 9: reads the file line by line 
 * 10: uses the split function and puts all the elements in a temp array
 * 11: set counter = to the return value of the split function
 * 12: checks if j is greater than or equal to the user array size, if so breaks out of the loop
 * 13: sets the username of the user object with position j = to the fist element of the temp array and number of users stored increments by one
 * 14: for every i till 50 then 
 * 15:	checks if the  (i + 1) is less than the counter then
 * 16:		sets the rating at index i of the user object with position j with the value at temp array (i + 1)
 * 17:	end if 
 * 18: j increments by one
 * 19: repeat from step 9 until there are no more lines in the file
 * 20: return the number of users stored
 */ 

int Library::readRatings(string fileName)
{
	ifstream in_file;
	in_file.open(fileName);
	string line;
	string temp_Arr[51];
	int counter;
	int i;
	int j = numUsers;

	if (numUsers == sizeUser) // checks if the number of users is equal to the user array size,  if so returns -2
	{
		return -2;
	}

	if (in_file.fail()) // checks if the file doesn't exist, if so returns -1
	{
		return -1;
	}
	else
	{
		while ((users[j].getUsername() != "")) // keeps checking if the username of the user object at index j is not empty, if so j and the numUsers increment by one
		{
			j++;
			numUsers++;
		}

		while (getline(in_file, line))
		{
			if (line != "")
			{
				split(line, ',', temp_Arr, 51);
				counter = split(line, ',', temp_Arr, 51);

				if (j >= sizeUser) // checks if j is equal to the max number of rows, if so breaks
				{
					break;
				}

				users[j].setUsername(temp_Arr[0]);
				numUsers++;
				
				for (i = 0; i < 50; i++)
				{
					if ( ((i + 1) < counter)) // checks if (i + 1) is less than the counter
					{
						users[j].setRatingAt(i, stoi(temp_Arr[i + 1]));
					}
				}
				j++;
			}
		}
		
		
		return numUsers;
	}

}

/**
 * Algorithm: prints all the ratings and titles from a certain user that are above or equal to the given minimum rating
 * 1: set i, counter = 0 and isThereUser = false
 * 2: for every i till the number of users then 
 * 3:   if if by using the checkIfSame function the username of the user object with index i is = to the given username then
 * 4:       posUser = i and isThereUser = true
 * 5:   end if
 * 6: end for
 * 7: if isThereUser is false then
 * 8:   prints userName " does not exist."
 * 9: end if
 * 10: else
 * 11:  for every i till the number of books then
 * 12:      if the rating at index i of the user with index posUser is not equal to 0 and greater than or equal to the minimum rating then
 * 13:          counter increments by one
 * 14:          if the counter is 1 then
 * 15:              print "Here are the books that " userName " rated"
 * 16:          end if
 * 17:          prints the title and rating of the of the book with index i and the rating with index i of the user with index posUser
 * 18:     end if
 * 19:  end for
 * 20:  if the counter is equal to 0 then
 * 21:      print userName " has not rated any books yet."
 * 22:  end if
 *
 */ 

void Library::viewRatings(string userName, int minRating)
{
    int posUser;
    bool isThereUser = false;
    int counter = 0;
    int i;
    
    for(i = 0; i < numUsers; i++)
    {
        if(checkIfSame(users[i].getUsername(), userName) == true) // checks  if if by using the checkIfSame function the username of the user object with index i is = to the given username
        {
            posUser = i;
            isThereUser = true;
        }
    }
    
    if(isThereUser == false) // checks if the user is not found
    {
        cout << userName << " does not exist." << endl;
    }
    else
    {
        for(i = 0; i < numBooks; i++)
        {
            if( (users[posUser].getRatingAt(i) != 0) && (users[posUser].getRatingAt(i) >= minRating )) // checks if the rating at index i of the user with index posUser is not equal to 0 and greater than or equal to the minimum rating
            {
                counter++;
                
                if(counter == 1)
                {
                    cout << "Here are the books that " << userName << " rated"<< endl;
                } 
                
                cout << "Title : " << books[i].getTitle() << endl;
                cout << "Rating : " << users[posUser].getRatingAt(i) << endl;
                cout << "-----" << endl;
            }
        }
        
        if(counter == 0)
        {
            cout << userName << " has not rated any books yet." << endl;
        }
    }
    
}

/**
 * Algorithm: calculates the avergae of the ratings the each user gave to a ceratin title
 * 1: set i =0 
 * 2: set j and sum = 0
 * 3: set isThereTitle = false
 * 4: for every i till the number of books then
 * 5:   if by using the checkIfSame function the title of the book object with index i is = to the given title then
 * 6:       set posTitle = i and isThereTitle = true
 * 7:   end if
 * 8: end for
 * 9: checks if isThereTitle is false or the number of Users is equal to 0, if so returns -3
 * 10: else 
 * 11:  for every i till the number of users then
 * 12:      if the rating with index posTitle of the user object with index i is not equal to 0 then
 * 13:          sum is equal to sum + rating with index posTitle of the user object with index i, and j increments by one
 * 14:      end if
 * 15:  end for
 * 16:  checks if sum is == to 0, if so returns 0, else returns sum / j
 */

double Library::calcAvgRating(string title)
{
    int i;
    int j = 0;
    int posTitle;
    double avg;
    int sum = 0;
    bool isThereTitle = false;
    
    for(i = 0; i < numBooks; i++) // finds the position where the title of the book object is equal to the given userName
    {
        if(checkIfSame(books[i].getTitle(), title))
        {
            posTitle = i;
            isThereTitle = true;
        }
    }
    
    if( (isThereTitle == false) || (numUsers == 0) ) // checks if isThereTitle is false or the number of Users is equal to 0, if so returns -3
    {
        return -3;
    }
    else
    {
        for(i = 0; i < numUsers; i++)
        {
             if(users[i].getRatingAt(posTitle) != 0) //  if the rating with index posTitle of the user object with index i is not equal to 0 
             {
                sum += users[i].getRatingAt(posTitle);
                j++;
             }
        }
        
        avg = (double)(sum) / (double)(j);
        
        if(sum == 0)
        {
            return 0;
        }
        else
        {
            return avg;
        }
    }
}

/**
 * Algorithm: calculates the avergae rating by the given author
 * 1: set i, j, y, k, sum, counter, countTitles = 0 and set isThereAuthor = false
 * 2: declare an integer array called posTitles of size 50
 * 3: for every i till the number of books then
 * 4:   if by using the checkIfSame function if the author of books with index i is equal to the given author then
 * 5:       posTitles with index j = i
 * 6:       j increments by one
 * 7:       countTitles increments by one
 * 8:       isThereAuthor = true
 * 9:   end if 
 * 10: end for
 * 11: if isThereAuthor is false or the number of users is 0 then
 * 12:      returns -3
 * 13: end if
 * 14: else
 * 15:      for every i till countTitles then 
 * 16:          for every y till the number of users then
 * 17:              if the rating with index posTitle[k] of the user with index y is not equal to 0 then
 * 18:                  sum = sum + rating with index posTitle[k] of the user with index y
 * 19:                  counter increments by one
 * 20:          end for
 * 21:          k increments by one
 * 22:      end for
 * 23:      average = sum divided by counter
 * 24:      if the sum is equal to 0 or counter is equal to 0 then
 * 25:          return 0
 * 26       end if
 * 27:      else
 * 28:          return average
 *
 */ 

double Library::calcAvgRatingByAuthor(string author)
{
    int posTitles[50];
    int i;
    int j = 0;
    int y;
    int k = 0;
    int sum = 0;
    int counter = 0;
    double avg;
    int countTitles = 0;
    bool isThereAuthor = false;
    
    for(i = 0; i < numBooks; i++)
    {
        if(checkIfSame(books[i].getAuthor(), author) == true) //  checks if by using the checkIfSame function if the author of books with index i is equal to the given author
        {
            posTitles[j] = i;
            j++;
            countTitles++;
            isThereAuthor = true;
        }
    }
    
    if( (isThereAuthor == false) || (numUsers == 0 )) // checks if isThereAuthor is false or the number of users is 0
    {
        return -3;
    }
    else
    {
        for(i = 0; i < countTitles ; i++)
        {
            for(y = 0; y < numUsers; y++)
            {
                if(users[y].getRatingAt(posTitles[k]) != 0) // checks if the rating with index posTitle[k] of the user with index y is not equal to 0 
                {
                    sum += users[y].getRatingAt(posTitles[k]);
                    counter++;
                }
            }
            k++;
        }
        avg = (double)(sum) / (double)(counter);
        
        if( (sum == 0) || (counter == 0) )
        {
            return 0;
        }
        else
        {
            return avg;
        }
    }
}

/**
 * Algorithm: adds a user to the users array
 * 1: set i = 0 and userExists = false
 * 2: if the number of users is equal 100 then 
 * 3: return -2
 * 4: for every i till the number of users then
 * 5:   if by using tye checkIfSame function if the username of the user with index i is equal to the given userName then
 * 6:       userExists = true
 * 7:   end if 
 * 8: end for
 * 9: if userExists is true then
 * 10:  return 0
 * 11: else
 * 12:  set the username of users with index numUsers equal to the given username
 * 13:  numUsers increments by one
 * 14:  return 1
 * 
 */ 

int Library::addUser(string userName)
{
    int i;
    bool userExists = false;
    
    if(numUsers == 100)
    {
        return -2;
    }
    
    for(i = 0; i < numUsers; i++)
    {
        if(checkIfSame(users[i].getUsername(), userName) == true)
        {
            userExists = true;
        }
    }
    
    if(userExists == true)
    {
        return 0;
    }
    else
    {
        users[numUsers].setUsername(userName);
        numUsers++;
        return 1;
    }
}

/**
 * Algorithm: sets the rating of a given username and title to a new rating
 * 1: set isThereUser and isThereTitle = false and i = 0
 * 2: if the new rating is between 0 and 5 and equal to 0 and 5 then
 * 3:   isValid = true
 * 4: end if 
 * 5: else
 * 6:   isValid = false
 * 7: for every i till the number of users then 
 * 8:   if by using checkIfSame if the username of user with index i is equal to the username then
 * 9:       posUser = i
 * 10:      isThereUser= true
 * 11:  end if
 * 12: end for
 * 13: for every i till the number of books then 
 * 14:   if by using checkIfSame if the title of book with index i is equal to the title then
 * 15:       posTitle = i
 * 16:      isThereTitle= true
 * 17:  end if
 * 18: end for
 * 19: if isValid is false then
 * 20:  return -4
 * 21: else if isThereUser or isThereTitle are false then
 * 22:  return -3
 * 23: end else if
 * 24: else
 * 25:  set the rating with index posTitle of the user with index posUser to the new rating
 * 26:  return 1
 * 
 */ 

int Library::checkOutBook(string userName, string title, int newRating)
{
    int posUser;
    int posTitle;
    bool isValid;
    bool isThereUser = false;
    bool isThereTitle = false;
    int i;
    
    if( (newRating >= 0) && (newRating <= 5) ) // checks if the new rating is between 0 and 5 and equal to 0 and 5
    {
        isValid = true;
    }
    else
    {
        isValid = false;
    }
    
    for(i = 0; i < numUsers; i++)
    {
        if(checkIfSame(users[i].getUsername(), userName) == true) // checks if by using checkIfSame if the username of user with index i is equal to the username
        {
            posUser = i;
            isThereUser = true;
            break;
        }
    }
    
    for(i = 0; i < numBooks; i++)
    {
        if(checkIfSame(books[i].getTitle(), title) == true) // checks if by using checkIfSame if the title of book with index i is equal to the title
        {
            posTitle = i;
            isThereTitle = true;
            break;
        }
    }
    
    if(isValid == false)
    {
        return -4;
    }
    else if( (isThereUser == false) || (isThereTitle == false) )
    {
        return -3;
    }
    else
    {
        users[posUser].setRatingAt(posTitle, newRating);
        return 1;
    }
}

/**
 * Algorithm: gets how many books were rated by a certain user
 * 1: set i = 0
 * 2: set rating counter = 0
 * 3: set isThereUser = false
 * 4: for every i till the number of users then
 * 5:   if by using the checkIfSame function the username of the user object with index i is = to the given username then
 * 6:       set posUser = i and isThereUser = true
 * 7:   end if
 * 8: end for
 * 9: checks if the isThereUser is equal to false or if the number of books is equal to 0, if so returns -3
 * 10: else
 * 11:  for every i till the number of books then
 * 12:      if the rating with index i for the user object with index posUser is not equal to 0 then
 * 13:          rating counter increments by one
 * 14:      end if
 * 15:  end for
 * 16: returns the rating counter
 */ 

int countReadBooks(string userName, User users[], int numUsers, int numBooks)
{
    int i;
    int ratingCounter = 0;
    int posUser;
    bool isThereUser = false;
    
    for(i = 0; i < numUsers; i++) // finds the position where the userName of the user object is equal to the given userName
    {
        if(checkIfSame(users[i].getUsername(), userName) == true)
        {
            posUser = i;
            isThereUser = true;
        }
    }
    
    if( (isThereUser == false) || (numBooks == 0) ) // checks if isThereUser is false or if the numBooks is equal to 0, if so returns -3
    {
        return -3;
    }
    else
    {
        for(i = 0; i < numBooks; i++)
        {
            if(users[posUser].getRatingAt(i) != 0) // checks if the rating with index i for the user object with index posUser is not equal to 0, if so increments ratingCounter by one
            {
                ratingCounter++;
            }
        }
    
        
        return ratingCounter;
    }
    
}

/**
 * Algorithm: gets recommendations for a given user
 * 1:set isThereUser, isNewUser, newUser = false and set i, j, recommendations, counter, ssd = 0 and set besSSD = 99999999
 * 2: for every i till the number of users then
 * 3:    if by using the checkIfSame function the username of the user object with index i is = to the given username then
 * 4:       posUser = i
 * 5:       isThereUser = true
 * 6:       break out of loop
 * 7:   end if
 * 8: end for
 * 9: if by using the countReadBooks function if the user found has not read anybooks then
 * 10:  newUser = true
 * 11: end if
 * 12: if isThereUser is false then 
 * 13:  print username " does not exist."
 * 14: end if
 * 15: else
 * 16:  for every i till the number of users then 
 * 17:      if i is not equal t posUser then
 * 18:          if by using the countReadBooks function if the user with index i has not read anybooks then
 * 19:              isNewUser = true
 * 20:          end if
 * 21:          else
 * 22:              isNewUser = false
 * 23:          if isNewUser is false then
 * 24:              for ever j till the number of books then
 * 25:                  if newUser is true then
 * 26:                      sd = the rating with index j of the user with index i 
 * 27:                  end if
 * 28:                  else 
 * 29:                      sd = the rating with index j of the user with index posUser subtracted by the rating with index j of the user with index i
 * 30:                  ssd = ssd + sd^2
 * 31:              end for
 * 32:              if ssd is less than bestSSD then
 * 33:                  bestSSD = ssd
 * 34:                  posMostSim = i
 * 35:              end if
 * 36:              ssd = 0
 * 37:      end if
 * 38:  end for
 * 39: for every i till the number of books then
 * 40:  if counter is equal to 5 then 
 * 41:      break out of the loop
 * 42:  end if
 * 43:  if the rating with index i of the user with index posMostSim is >= 3 and the rating with index i of the user with index posUser is equal to 0 then
 * 44:      recommendation and counter increment by one
 * 45:      if recommenddations is equal to 1 then
 * 46:          print "Here is a list of recommendations"
 * 47:      end if
 * 48:      print title of the book with index i " by " the author of the book with index i
 * 49:  end if
 * 50: end for
 * 51: if recommendation is equal to 0 then
 * 52:  print "There are no recommendations for " username " at present."
 * 
 */ 

void Library::getRecommendations(string userName)
{
    int posUser;
    int posMostSim;
    bool isThereUser = false;
    bool isNewUser = false;
    bool newUser = false;
    int bestSSD = 99999999;
    int sd;
    int ssd = 0;
    int i;
    int j;
    int recommendations = 0;
    int counter = 0;
    
    for(i = 0; i < numUsers; i++)
    {
        if(checkIfSame(users[i].getUsername(), userName) == true) // checks if by using the checkIfSame function the username of the user object with index i is = to the given username
        {
            posUser = i;
            isThereUser = true;
            break;
        }
    }
    
    if(countReadBooks(userName, users, numUsers, numBooks) == 0) //  checcks if by using the countReadBooks function if the user found has not read anybooks
    {
        newUser == true;
    }
    
    if(isThereUser == false)
    {
        cout << userName << " does not exist." << endl;
    }
    else
    {
        for(i = 0; i < numUsers; i++)
        {
            if(i != posUser)
            {
                if(countReadBooks(users[i].getUsername(), users, numUsers, numBooks) == 0) //  checks if by using the countReadBooks function if the user with index i has not read anybooks
                {
                    isNewUser = true;
                }
                else
                {
                    isNewUser = false;
                }
                
                if(isNewUser == false)
                {
                    for(j = 0; j < numBooks; j++)
                    {
                        if(newUser == true)
                        {
                            sd = users[i].getRatingAt(j);
                        }
                        else
                        {
                            sd = (users[posUser].getRatingAt(j)) - (users[i].getRatingAt(j));
                        }
                        
                        ssd += pow(sd, 2);
                            
                    
                    }
                    
                    if(ssd < bestSSD)
                    {
                        bestSSD = ssd;
                        posMostSim = i;
                    }
                    
                    ssd = 0;
                    
                }
            }
        }
        
        for(i = 0; i < numBooks; i++)
        {
            if(counter == 5)
            {
                break;
            }
            
            if( (users[posMostSim].getRatingAt(i) >= 3) && (users[posUser].getRatingAt(i) == 0)) // checks if the rating with index i of the user with index posMostSim is >= 3 and the rating with index i of the user with index posUser is equal to 0
            {
                recommendations++;
                counter++;
                
                if(recommendations == 1)
                {
                    cout << "Here is the list of recommendations" << endl;
                }
                
                cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
            }
        }
        
        if(recommendations == 0)
        {
            cout << "There are no recommendations for " << userName <<  " at present." << endl;
        }
    }
}