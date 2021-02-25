#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <vector>
#include "Pokemon.h"

using namespace std;

class Player
{
    private:
        int pokeBalls;
        string playerName;
        vector<Pokemon> myPokemons;
        int badges;
        int points;
        vector<string> types;
        int numPokemons;
        int rowLoc;
        int colLoc;
        
    public:
        string getPlayerName();
        Pokemon getPoke(int idx);
        int getNumPokemons();
        int getPokeBalls();
        int getBadges();
        int getPoints();
        int getRowLoc();
        int getColLoc();
        int getPokemonHP(int idx);
        string getPokeN(int idx);
        int getPokeA(int idx);
        int getPokeD(int idx);
        int getPokeS(int idx);
        int getPokeM(int idx);
        int getMaxPokemonHP(int idx);
        bool getActivePoke(int idx);
        bool getPokeF(int idx);
        int getPokeL(int idx);
        vector<string> getDiffTypes();
        vector<Pokemon> getPokemons();
        
        void setRowLoc(int r);
        void setColLoc(int c);
        void setPlayerName(string name);
        void setPokemons(string pokemonName);
        void setDiffTypes(string thisType);
        
        void healPoke(int idx, int h);
        void insertPoke(int idx, Pokemon &poke);
        void erasePoke(int idx);
        void addBadge(int b);
        void addToHP(int idx, int num);
        void addPoints(int point);
        void subtractPoints(int point);
        void addPokeBall(int num);
        void subtractPokeBall(int num);
        void updateRowLoc(int r);
        void updateColLoc(int c);
        void changeToActive(int idx, bool a);
        
        void changePokeF(int idx, bool f);
        void changePokeHP(int idx, int h);
        void changePokeA(int idx, int a);
        void changePokeD(int idx, int d);
        void changePokeS(int idx, int s);
        void changePokeMaxHP(int idx, int h);
        
        void levelA(int idx, int a);
        void levelD(int idx, int d);
        void levelS(int idx, int s);
        void levelUP(int idx);
        
        Player();
        
};

#endif