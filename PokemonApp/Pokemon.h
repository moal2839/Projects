#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

class Pokemon
{
    private:
        int index;
        int HP;
        int A;
        int D;
        int S;
        int max;
        int maxHP;
        vector<string> types;
        string name;
        int level;
        bool active;
        bool faint;
        
    public:
        int getIndex();
        bool getFaint();
        int getHP();
        int getA();
        int getD();
        int getS();
        int getM();
        int getMaxHP();
        bool getActive();
        int getLevel();
        vector<string> getTypes();
        string getName();
        
        void setFaint(bool f);
        void setIndex(int idx);
        void setMaxHP(int hp);
        void setHP(int health);
        void setA(int attack);
        void setD(int defense);
        void setS(int speed);
        void setMax(int m);
        void setName(string thisName);
        void setTypes(string type);
        
        void changeActive(bool a);
        void changeHP(int num);
        void changeA(int num);
        void changeD(int num);
        void changeS(int num);
        void changeL(int num);
        
        Pokemon();
};

#endif