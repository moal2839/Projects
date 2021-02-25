#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include "Player.h"

using namespace std;

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

int Player::getNumPokemons()
{
    return myPokemons.size();
}

string Player::getPlayerName()
{
    return playerName;
}

int Player::getPokeBalls()
{
    return pokeBalls;
}

int Player::getBadges()
{
    return badges;
}

int Player::getPoints()
{
    return points;
}

vector<Pokemon> Player::getPokemons()
{
    return myPokemons;
}

int Player::getRowLoc()
{
    return rowLoc; // corresponds to the row location of the player
}

int Player::getColLoc()
{
    return colLoc; // corresponds to the column location of the player
}

int Player::getPokemonHP(int idx)
{
    return myPokemons[idx].getHP(); // gets the health points for the pokemon with index idx in the player's roster of pokemon
}

int Player::getMaxPokemonHP(int idx)
{
    return myPokemons[idx].getMaxHP(); // gets max health for the pokemon with index idx
}

int Player::getPokeA(int idx)
{
    return myPokemons[idx].getA(); // gets the attack stat for the pokemon with index idx
}

int Player::getPokeD(int idx)
{
    return myPokemons[idx].getD(); // gets the defense stat for the pokemon with index idx
}

int Player::getPokeS(int idx)
{
    return myPokemons[idx].getS(); // gets the speed stat for the pokemon with index idx
}

int Player::getPokeM(int idx)
{
    return myPokemons[idx].getM(); // gets the max stat for the pokemon with index idx
}

bool Player::getActivePoke(int idx)
{
    return myPokemons[idx].getActive(); // gets if the pokemon with index idx is active or not
}

string Player::getPokeN(int idx)
{
    return myPokemons[idx].getName(); // gets the name of the pokemon with index idx
}

Pokemon Player::getPoke(int idx)
{
    return myPokemons[idx]; // gets the pokemon with index idx 
}

bool Player::getPokeF(int idx)
{
    return myPokemons[idx].getFaint();
}

int Player::getPokeL(int idx)
{
    return myPokemons[idx].getLevel();
}

vector<string> Player::getDiffTypes()
{
    return types;
}

void Player::setDiffTypes(string thisType)
{
    int i;
    bool isThereSame = false;
    
    if(types.size() == 0) // if it is the first type that the player gets then it just gets pushed back into the vector types
    {
        types.push_back(thisType);
    }
    else
    {
        for(i = 0; i < types.size(); i++) // loops through the vector types and checks if the type given occurs in the vector, if so the isThereSame becomes true
        {
            if(thisType == types[i])
            {
                isThereSame = true;
            }
        }
        
        if(isThereSame == false) // checks if the type already occurs in the vector, if not then it gets pushed back in the vector of types
        {
            types.push_back(thisType);
        }
    }
    
    for(i = 0; i < types.size(); i++) // loops through the vector of types and erases any instances of an empty string
    {
        if(types[i] == "")
        {
            types.erase(types.begin() + i);
        }
    }
    
}

void Player::addToHP(int idx, int num)
{
    myPokemons[idx].changeHP(num); // adds to the HP of the pokemon with index idx
}

void Player::setRowLoc(int r)
{
    rowLoc = r;
}

void Player::setColLoc(int c)
{
    colLoc = c;
}

void Player::setPokemons(string pokemonName)
{
    ifstream in_file;
    in_file.open("pokemon.txt");
    string line;
    Pokemon tempPokemon;
    string tempLine[9];
    int numSplits;
    
    while(getline(in_file, line))
    {
        numSplits = split(line, ',', tempLine, 9);
        
        if(tempLine[1] == pokemonName) // checks if the pokemon name from the file is the same as the one given, in other words if the pokemon is found from the file
        {
            tempPokemon.setIndex( stoi(tempLine[0]) - 1); // sets the index of the pokemon to the first element in that line file
            tempPokemon.setName(tempLine[1]); // sets the name of the pokemon to the second element in that line file
            tempPokemon.setHP( stoi(tempLine[2]) ); // sets the HP of the pokemon to the third element of that line file
            tempPokemon.setMaxHP( stoi(tempLine[2]) ); // sets the max HP that the pokemon can have untilit levels up to the third element of that line
            tempPokemon.setA( stoi(tempLine[3]) ); // sets the attack of the pokemon to fourth element of that line
            tempPokemon.setD( stoi(tempLine[4]) ); // sets the defense of the pokemon to fifth element of that line
            tempPokemon.setS( stoi(tempLine[5]) ); // sets the speed of the pokemon to sixth element of that line
            tempPokemon.setMax( stoi(tempLine[6]) ); // sets the max of the pokemon to seventh element of that line
            
            if(numSplits > 8) // if the number of splits on the line are more than 8, or in other words if the pokemon has two types
            {
                tempPokemon.setTypes(tempLine[7]); // sets type 1
                tempPokemon.setTypes(tempLine[8]); // sets type 2
                setDiffTypes(tempLine[7]); // sets the type 1 in the vector of types for the player
                setDiffTypes(tempLine[8]); // sets the type 2 in the vector of types for the player
            }
            else
            {
                tempPokemon.setTypes(tempLine[7]);
                setDiffTypes(tempLine[7]);
            }
            
            myPokemons.push_back(tempPokemon); // the temporary pokemon gets pushed back into the vector myPokemons that belongs to the Player
        }
        
    }
}

void Player::setPlayerName(string name)
{
    playerName = name;
}

void Player::insertPoke(int idx, Pokemon &poke)
{
    myPokemons.insert(myPokemons.begin() + idx, poke); // inserts a pokemon into the roster of player's pokemons on the index idx
}

void Player::erasePoke(int idx)
{
    myPokemons.erase(myPokemons.begin() + idx); // erases the pokemon from myPokemons with index idx
}

void Player::addPoints(int point)
{
    points += point;
}

void Player::subtractPoints(int point)
{
    points -= point;
}

void Player::addPokeBall(int num)
{
    pokeBalls += num;
}

void Player::subtractPokeBall(int num)
{
    pokeBalls -= num;
}


void Player::updateRowLoc(int r)
{
    rowLoc += r;
}

void Player::updateColLoc(int c)
{
    colLoc += c;
}

void Player::healPoke(int idx, int h)
{
    myPokemons[idx].setHP(h);
}

void Player::levelA(int idx, int a)
{
    myPokemons[idx].setA(a); // levels up the pokemon's with index idx attack stat with the value a
}

void Player::levelD(int idx, int d)
{
    myPokemons[idx].setD(d); // levels up the pokemon's with index idx defense stat with the value d
}

void Player::levelS(int idx, int s)
{
    myPokemons[idx].setS(s); // levels up the pokemon's with index idx speed stat with the value s
}

void Player::levelUP(int idx)
{
    myPokemons[idx].changeL(1); // levels up the pokemon with index idx by one
}

void Player::changeToActive(int idx, bool a)
{
    myPokemons[idx].changeActive(a); // changes the pokemon with index idx active status to a
}

void Player::changePokeHP(int idx, int h)
{
    myPokemons[idx].changeHP(h); 
}

void Player::changePokeA(int idx, int a)
{
    myPokemons[idx].changeA(a);
}

void Player::changePokeD(int idx, int d)
{
    myPokemons[idx].changeD(d);
}

void Player::changePokeS(int idx, int s)
{
    myPokemons[idx].changeS(s);
}

void Player::changePokeF(int idx, bool f)
{
    myPokemons[idx].setFaint(f);
}

void Player::changePokeMaxHP(int idx, int h)
{
    myPokemons[idx].setMaxHP(h);
}

void Player::addBadge(int b)
{
    badges += b;
}

Player::Player()
{
    pokeBalls = 10;
    playerName = "";
    badges = 0;
    points = 0;
}