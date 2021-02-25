#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Pokemon.h"

using namespace std;

int Pokemon::getLevel()
{
    return level;
}

int Pokemon::getIndex()
{
    return index;
}

int Pokemon::getMaxHP()
{
    return maxHP;    
}

string Pokemon::getName()
{
    return name;
}

int Pokemon::getHP()
{
    return HP;
}

int Pokemon::getA()
{
    return A;
}

int Pokemon::getD()
{
    return D;
}

int Pokemon::getS()
{
    return S;
}

int Pokemon::getM()
{
    return max;
}

bool Pokemon::getActive()
{
    return active;
}

bool Pokemon::getFaint()
{
    return faint;
}

vector<string> Pokemon::getTypes()
{
    return types;
}

void Pokemon::setFaint(bool f)
{
    faint = f;
}

void Pokemon::setIndex(int idx)
{
    index = idx;
}

void Pokemon::setMaxHP(int hp)
{
    maxHP = hp;
}

void Pokemon::setHP(int health)
{
    HP = health;
}

void Pokemon::setA(int attack)
{
    A = attack;
}

void Pokemon::setD(int defense)
{
    D = defense;
}

void Pokemon::setS(int speed)
{
    S = speed;
}

void Pokemon::setMax(int m)
{
    max = m;
}

void Pokemon::setName(string thisName)
{
    name = thisName;
}

void Pokemon::setTypes(string type)
{
    types.push_back(type);
}

void Pokemon::changeHP(int num)
{
    HP += num;
}

void Pokemon::changeA(int num)
{
    A += num;
}

void Pokemon::changeD(int num)
{
    D += num;
}

void Pokemon::changeS(int num)
{
    S += num;
}

void Pokemon::changeActive(bool a)
{
    active = a;
}

void Pokemon::changeL(int num)
{
    level += num;
}

Pokemon::Pokemon()
{
    maxHP = 0;
    HP = 0;
    A = 0;
    D = 0;
    S = 0;
    name = "";
    active = false;
    faint = false;
    level = 1;
}
