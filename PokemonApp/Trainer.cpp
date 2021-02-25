#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
#include "Trainer.h"

using namespace std;

Pokemon Trainer::getPokemon(int idx)
{
    return trainersPokemon[idx]; // gets a pokemon from the trainer with index idx
}

int Trainer::getIdx()
{
    return idx;
}

int Trainer::getNumPokemons()
{
    return numPokemons; // gets the number of pokemons that a trainer has in their roster
}

string Trainer::getTrainerName()
{
    return trainersName;
}

int Trainer::getPokeI(int idx)
{
    return trainersPokemon[idx].getIndex();
}

string Trainer::getPokeName(int idx)
{
    return trainersPokemon[idx].getName(); // gets the pokemon's name with index idx from the trainersPokemon
}

int Trainer::getPokeHP(int idx)
{
    return trainersPokemon[idx].getHP(); // gets the pokemon's HP with index idx from the trainersPokemon
}

int Trainer::getPokeAt(int idx)
{
    return trainersPokemon[idx].getA(); // gets the pokemon's Attack with index idx from the trainersPokemon
}

int Trainer::getPokeDef(int idx)
{
    return trainersPokemon[idx].getD(); // gets the pokemon's Defense with index idx from the trainersPokemon
}

int Trainer::getPokeMaxHP(int idx)
{
    return trainersPokemon[idx].getMaxHP(); // gets the pokemon's MaxHP with index idx from the trainersPokemon
}

int Trainer::getPokeSp(int idx)
{
    return trainersPokemon[idx].getS(); // gets the pokemon's Speed with index idx from the trainersPokemon
}

int Trainer::getPokeLv(int idx)
{
    return trainersPokemon[idx].getLevel(); // gets the pokemon's level with index idx from the trainersPokemon
}

int Trainer::getPokeMx(int idx)
{
    return trainersPokemon[idx].getM(); // gets the pokemon's max with index idx from the trainersPokemon
}

vector<Pokemon> Trainer::getPokes()
{
    return trainersPokemon; //returns the whole roster of pokemons that belong to the trainer
}

void Trainer::setIdx(int thisIdx)
{
    idx = thisIdx;
}

void Trainer::setNumPokemons(int num)
{
    numPokemons = num;
}

void Trainer::setTrainerPokemons(string pokemonName)
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
            }
            else
            {
                tempPokemon.setTypes(tempLine[7]);
            }
            
            trainersPokemon.push_back(tempPokemon); // the temporary pokemon gets pushed back to the vector of trainersPokemon that belongs to the trainer
        }
        
    }
}

void Trainer::setTrainerName(string name)
{
    trainersName = name;
}

void Trainer::changeMyPokeHP(int idx, int h)
{
    trainersPokemon[idx].changeHP(h);
}

void Trainer::levelHP(int idx, int h)
{
    trainersPokemon[idx].setHP(h); // levels up HP for the pokemon with index idx in the trainers party
}

void Trainer::levelAt(int idx, int a)
{
    trainersPokemon[idx].setA(a); // levels up Attack for the pokemon with index idx in the trainers party
}

void Trainer::levelDef(int idx, int d) // levels up Defense for the pokemon with index idx in the trainers party
{
    
    trainersPokemon[idx].setD(d);
}

void Trainer::levelSp(int idx, int s) // levels up Speed for the pokemon with index idx in the trainers party
{
    trainersPokemon[idx].setS(s);
}

void Trainer::level(int idx) // levels up the pokemon with index idx by one 
{
    trainersPokemon[idx].changeL(1);
}

void Trainer::changePokeMxHP(int idx, int h)
{
    trainersPokemon[idx].setMaxHP(h); // changes the pokemon with index idx max HP to h when it levels up 
}

Trainer::Trainer()
{
    trainersName = "";
    idx = 0;
    numPokemons = 0;
}