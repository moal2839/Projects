#ifndef TRAINER_H
#define TRAINER_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include "Pokemon.h"

using namespace std;

class Trainer
{
    private:
        vector<Pokemon> trainersPokemon;
        string trainersName;
        int idx;
        int numPokemons;
    
    public:
        Pokemon getPokemon(int idx);
        int getPokeMaxHP(int idx);
        int getIdx();
        int getNumPokemons();
        string getTrainerName();
        int getPokeI(int idx);
        string getPokeName(int idx);
        int getPokeHP(int idx);
        int getPokeAt(int idx);
        int getPokeDef(int idx);
        int getPokeSp(int idx);
        int getPokeMx(int idx);
        int getPokeLv(int idx);
        vector<Pokemon> getPokes();
        
        void setIdx(int thisIdx);
        void setNumPokemons(int num);
        void setTrainerName(string name);
        void setTrainerPokemons(string pokeName);
        
        void changeMyPokeHP(int idx, int h);
        void changePokeMxHP(int idx, int h);
        
        void levelHP(int idx, int h);
        void levelAt(int idx, int a);
        void levelDef(int idx, int d);
        void levelSp(int idx, int s);
        void level(int idx);
        
        Trainer();
        
};

#endif