#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
//#include "Player.cpp"
//#include "Main.cpp"

using namespace std;

int main()
{
	Main myMain;
	int choice = 0;
	myMain.genF();
	myMain.genC();
	myMain.startGame();
	myMain.readMap();
	myMain.readPokemons();
	myMain.generateTrainers();
	myMain.printMap();
	myMain.yourTurn();
	cout << endl;
	myMain.printMap();
}