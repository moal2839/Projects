#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
//#include "Pokemon.cpp"
//#include "Trainer.cpp"
//#include "Player.cpp"

using namespace std;

class Main
{
    private:
        string tiles[27][16];
        vector<Pokemon> allPokemons;
        vector<Pokemon> wildPokemons;
        vector<Trainer> trainers;
        Player myPlayer;
        int Encounters = 0;
        bool quitBattle = false;
        bool quitTrainerBattle = false;
        vector<int> wildPokemonsX;
        vector<int> wildPokemonsY;
        vector<int> C;
        vector<int> wF;
        int playerC = 0;
        
    public:
        void genF();
        void genC();
        void readMap();
        void pokeDex(int idx);
        void printMap();
        void printTiles();
        void readPokemons();
        void levelUp(int idx);
        void levelPlayerPoke(int idx);
        void levelTrainerPoke(int tIdx, int idx);
        void switchP();
        void run(int pokeIdx, int posActivePokemon);
        void fight(int pokeIdx, int posActivePokemon);
        void battle(int pokeIdx);
        void trainerEncounters();
        void fightTrainers(int trainerIdx, int posActivePokemon, int trainerActivePoke);
        void tryYourLuck();
        void generateTrainers();
        void catching();
        void yourTurn();
        void startGame();
        void endGame();
        void Center();
        void playerWins();
};

#endif