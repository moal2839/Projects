#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "Main.h"

using namespace std;

int splitMain(string sentence, char deli, string words[], int len)
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

void Main::genF()
{
    int i;
    
    for(i = 0; i < 20; i++) // pushes back 0 twenty times into the vector wF(will the pokemon fight, if it is 0 that means it wont if it is 1 it will)
    {
        wF.push_back(0);
    }
}

void Main::genC()
{
    int i;
    
    for(i = 0; i < 20; i++) // pushes back 0 twenty times into the vector C(number of times a wildPokemon tries to run in an encounter) 
    {
        C.push_back(0);
    }
}

void quitGame()
{
    cout << "Thanks for playing" << endl;
}

void Main::playerWins()
{
    cout << "Yoou won the game!" << endl;
}

char travelChoice()
{
    int choice;
    bool quit = false;
    char di;
    
    while(quit == false) // while the player keeps inputing wrong values as choice of where to go 
    {
        cout << "Choose which direction to go to: " << endl;
        cout << "1. North" << endl;
        cout << "2. East" << endl;
        cout << "3. West" << endl;
        cout << "4. South" << endl;
        cin >> choice;
        
        if(choice == 1)
        {
            di = 'N';
            quit = true;
        }
        else if(choice == 2)
        {
            di = 'E';
            quit = true;
        }
        else if(choice == 3)
        {
            di = 'W';
            quit = true;
        }
        else if(choice == 4)
        {
            di = 'S';
            quit = true;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
    
    return di;
    
}

void travel(char di, Player &myPlayer, string tiles[][16])
{
    int r = myPlayer.getRowLoc(); // gets the player's row
    int c = myPlayer.getColLoc(); // gets the player's column
    char direct;
    
    if(di == 'N')
    {
        if( (tiles[r - 1][c]  != "w") && ( (r - 1 >= 0)  &&  (r - 1 < 25) ) ) // checks if the tile is not water and if the change is within bounds of the map
        {
            myPlayer.updateRowLoc(-1);
        }
        else // if the condition is not met then asks for a different direction 
        {
            direct = travelChoice();
            travel(direct, myPlayer, tiles);
        }
    }
    else if(di == 'W')
    {
        if( (tiles[r][c - 1] != "w") && ( (c - 1 >= 0) && (c - 1 < 16) ) ) // checks if the tile is not water and if the change is within bounds of the map
        {
            myPlayer.updateColLoc(-1);
        }
        else // if the condition is not met then asks for a different direction 
        {
            direct = travelChoice();
            travel(direct, myPlayer, tiles);
        }
    }
    else if(di == 'E')
    {
        if( (tiles[r][c + 1] != "w") && ( (c + 1 >= 0) && (c + 1 < 16) ) )  // checks if the tile is not water and if the change is within bounds of the map
        {
            myPlayer.updateColLoc(1);
        }
        else // if the condition is not met then asks for a different direction 
        {
            direct = travelChoice();
            travel(direct, myPlayer, tiles);
        }
    }
    else
    {
        if( (tiles[r + 1][c]  != "w") && ( (r + 1 >= 0)  &&  (r + 1 < 25) ) ) // checks if the tile is not water and if the change is within bounds of the map
        {
            myPlayer.updateRowLoc(1);
        }
        else // if the condition is not met then asks for a different direction 
        {
            direct = travelChoice();
            travel(direct, myPlayer, tiles);
        }
    }
}

void Main::levelTrainerPoke(int tIdx, int idx)
{
    int changeInHP = ((double)(102)/100) * (trainers[tIdx].getPokeMaxHP(idx)); // increases the pokemons HP by 2%
    int changeInS = ((double)(102)/100) * (trainers[tIdx].getPokeSp(idx)); // increases the pokemons Speed by 2%
    int changeInA;
    int changeInD;
    int newA = ((double)(102)/100) * (trainers[tIdx].getPokeAt(idx)); // increases the pokemons Attack by 2%
    int newD = ((double)(102)/100) * (trainers[tIdx].getPokeDef(idx)); // increases the pokemons Defense by 2%
    trainers[tIdx].level(idx);
    
    if(newA <= trainers[tIdx].getPokeMx(idx)) //checks if the new Attack stat is less than or equal to the max
    {
        changeInA = newA;
        trainers[tIdx].levelAt(idx, changeInA);
    }
    
    if(newD <= trainers[tIdx].getPokeMx(idx)) //checks if the new Defense stat is less than or equal to the max
    {
        changeInD = newD;
        trainers[tIdx].levelDef(idx, changeInD);
    }
    
    trainers[tIdx].levelHP(idx, changeInHP);
    trainers[tIdx].changePokeMxHP(idx, changeInHP);
    trainers[tIdx].levelSp(idx, changeInS);
}

void Main::levelPlayerPoke(int idx)
{
    int changeInHP = ((double)(102)/100) * (myPlayer.getMaxPokemonHP(idx)); // increases the pokemons HP by 2%
    int changeInS = ((double)(102)/100) * (myPlayer.getPokeS(idx)); // increases the pokemons Speed by 2%
    int changeInA;
    int changeInD;
    int newA = ((double)(102)/100) * (myPlayer.getPokeA(idx)); // increases the pokemons Attack by 2%
    int newD = ((double)(102)/100) * (myPlayer.getPokeD(idx)); // increases the pokemons Defenses by 2%
    myPlayer.levelUP(idx);
    
    if(newA <= myPlayer.getPokeM(idx)) //checks if the new Attack stat is less than or equal to the max
    {
        changeInA = newA;
        myPlayer.levelA(idx, changeInA);
    }
    
    if(newD <= myPlayer.getPokeM(idx)) //checks if the new Defense stat is less than or equal to the max
    {
        changeInD = newD;
        myPlayer.levelD(idx, changeInD);
    }
    
    myPlayer.healPoke(idx, changeInHP);
    myPlayer.changePokeMaxHP(idx, changeInHP);
    myPlayer.levelS(idx, changeInS);
}

void Main::levelUp(int idx)
{
    int changeInHP = ((double)(102)/100) * (wildPokemons[idx].getMaxHP()); // increases the pokemons HP by 2%
    int changeInS = ((double)(102)/100) * (wildPokemons[idx].getS()); // increases the pokemons Speed by 2%
    int changeInA;
    int changeInD;
    int newA = ((double)(102)/100) * (wildPokemons[idx].getA()); // increases the pokemons Attack by 2%
    int newD = ((double)(102)/100) * (wildPokemons[idx].getD()); // increases the pokemons Defense by 2%
    wildPokemons[idx].changeL(1);
    
    if(newA <= wildPokemons[idx].getM()) //checks if the new Attack stat is less than or equal to the max
    {
        changeInA = newA;
        wildPokemons[idx].setA(changeInA);
    }
    
    if(newD <= wildPokemons[idx].getM()) //checks if the new Defense stat is less than or equal to the max
    {
        changeInD = newD;
        wildPokemons[idx].setD(changeInD);
    }
    
    wildPokemons[idx].setHP(changeInHP);
    wildPokemons[idx].setMaxHP(changeInHP);
    wildPokemons[idx].setS(changeInS);
    
}

void rest(Player &myPlayer)
{
    int i;
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++) //loops through all the pokemons that belong to the players party and checks if they're health is less than the max health, if so they're HP increase by one
    {
        if(myPlayer.getPokemonHP(i) < myPlayer.getMaxPokemonHP(i))
        {
            myPlayer.addToHP(i, 1);
        }
    }
    
    myPlayer.subtractPokeBall(1); 
}

void Main::startGame()
{
    string playerName;
    int choice;
    bool quit = false;
    
    cout << "Welcome to Pokemon!" << endl;
    cout << endl;
    cout << "Please state your name: ";
    // cin >> playerName;
    getline(cin, playerName);
    myPlayer.setPlayerName(playerName);
    cout << endl;
    cout << "Welcome, " << playerName << "! Before you can begin your Pokemon adventure,\nyou must choose a starting Pokemon, courtesy of the Professor. \nPlease choose from the following Pokemon:" << endl;
    
    while(quit == false) //loops until the player enters a valid option
    {
        cout << "1. Bulbasaur" << endl;
        cout << "2. Charmander" << endl;
        cout << "3. Squirtle" << endl;
        cout << "4. Pikachu" << endl;
        cout << endl;
        cin >> choice;
        
        
        if(choice == 1)
        {
            myPlayer.setRowLoc(12); // sets starting row for player
            myPlayer.setColLoc(6); // sets starting column for player
            myPlayer.setPokemons("Bulbasaur"); // sets Bulbasaur as the starting pokemon for the player
            myPlayer.changeToActive(0, true); // sets the first pokemon to be the active pokemon
            quit = true;
        }
        else if(choice == 2)
        {
            myPlayer.setRowLoc(12); // sets starting row for player
            myPlayer.setColLoc(7); // sets starting column for player
            myPlayer.setPokemons("Charmander"); // sets Charmander as the starting pokemon for the player
            myPlayer.changeToActive(0, true); // sets the first pokemon to be the active pokemon
            quit = true;
        }
        else if(choice == 3)
        {
            myPlayer.setRowLoc(12); // sets starting row for player
            myPlayer.setColLoc(8); // sets starting column for player
            myPlayer.setPokemons("Squirtle"); // sets Squirtle as the starting pokemon for the player
            myPlayer.changeToActive(0, true); // sets the first pokemon to be the active pokemon
            quit = true;
        }
        else if(choice == 4)
        {
            myPlayer.setRowLoc(12); // sets starting row for player
            myPlayer.setColLoc(9); // sets starting column for player
            myPlayer.setPokemons("Pikachu"); // sets Pikachu as the starting pokemon for the player
            myPlayer.changeToActive(0, true); // sets the first pokemon to be the active pokemon
            quit = true;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    }
}

void Main::readMap()
{
    ifstream in_file;
    in_file.open("mapPoke.txt");
    string line;
    string tempLine[16];
    int i = 0;
    int j;
    
    while(getline(in_file, line))
    {
        if(line != "")
        {
            split(line, ',', tempLine, 16);
            
            for(j = 0; j < 16; j++)
            {
                tiles[i][j] = tempLine[j]; //populates the 2D array tiles with the elements in the file mapPoke.txt
            }
            
            i++;
        }
    }
}

void Main::printMap()
{   
    int r = myPlayer.getRowLoc(); // gets player's row
    int c = myPlayer.getColLoc(); // gets player's column
    int i;
    int j;
    
    for(i = r - 3; i <= r + 3; i++)
    {
        for(j = c - 3; j <= c + 3; j++)
        {
                    
                if( (i == r) && (j == c)) // checks if the i and j are equal to the player's row and column respectively, if so print's out @ which represents the player
                {
                    cout << "@ ";
                }
                else if((i < 0) || (j < 0) || (i >= 25) || (j >= 16)) // checks if either the row or the columns are out of bounds, if so prints !
                {
                    cout << "! ";
                }
                else if(tiles[i][j] == "Z") // checks if the tile is occupied by a wild Pokemon, if so prints p
                {
                    cout << "p ";
                }
                else if(tiles[i][j] == "G") // checks if the tile is a pokemon gym, if so prints G
                {
                    cout << "G ";
                }
                else if(tiles[i][j] == "C") // checks if the tile is a pokemon center, if so prints C
                {
                    cout << "C ";
                }
                else if(tiles[i][j] == "w") // checks if the tile is water, if so prints ~
                {
                    cout << "~ ";
                }
                else
                {
                    cout << "* "; // plain land tiles are represented by *
                }
           
        }
        cout << endl;
    }
}

void Main::printTiles()
{
    int i;
    int j;
    
    for(i = 0; i < 25; i++)
    {
        for(j = 0; j < 16; j++) // prints the 2D array of tiles
        {
            cout << tiles[i][j];
            //cout << " ";
        }
        cout << endl;
    }
}

void Main::pokeDex(int idx)
{
    char answer;
    int i;
    
    cout << endl;
    cout << "Awesome! You acquired " << wildPokemons[idx].getName() << ", who joins the Pokedex. Your battle party is full.\nDo you want to add " 
    << wildPokemons[idx].getName() << " to your Active Party?\n(Y/N): " << endl;
    cin >> answer;
    
    if(answer == 'Y')
    {
        int counter = 0;
        int choice;
        
        cout << endl;
        cout << "Which Pokemon should not be part of the Active Party anymore: " << endl;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++) // prints the pokemons that are in the player's active party
        {
            counter++;
            
            if(i < 6)
            {
                cout << counter << ". " << myPlayer.getPokeN(i) << endl;
            }    
        }
        
        cin >> choice;
        int posUnWantedPoke = choice - 1; // stores the position of the pokemon that the player wants to replace
        Pokemon tempPokemon = myPlayer.getPoke(posUnWantedPoke); 
        
        myPlayer.erasePoke(posUnWantedPoke);
        myPlayer.insertPoke(posUnWantedPoke, wildPokemons[idx]); // the wild pokemon is inserted in place of the replaced pokemon
        myPlayer.insertPoke(myPlayer.getNumPokemons(), tempPokemon); // the replaced pokemon gets pushed back to the end of the player's roster of pokemons
        
        cout << endl;
        cout << "Great! The following Pokemon are now in your Active Party. Choose one\nof them to be your Active Pokemon: " << endl;
        cout << endl;
        
        int counterAct = 0;
        int choiceAct;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++) // prints the new list of party of pokemons 
        {
            counterAct++;
            
            if(i < 6)
            {
                cout << counterAct << ". " << myPlayer.getPokeN(i) << endl;
            }
        }
        
        cin >> choiceAct;
        
        int posWanted = choiceAct - 1; // stores the position of the pokemon to be active
        int posCurr;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
            {
                posCurr = i; // stores the position of the current active pokemon
                break;
            }
        }
        
        myPlayer.changeToActive(posCurr, false); // the current active pokemon becomes inactive
        myPlayer.changeToActive(posWanted, true); // the pokemon to be active becomes active
        
        int newAct;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            if(myPlayer.getActivePoke(i) == true)
            {
                newAct = i;
            }
        }
        
        cout << endl;
        cout << "Your ACTIVE Pokemon is: " << endl;
        cout << "Name: " << myPlayer.getPokeN(newAct) << ", HP: " << myPlayer.getPokemonHP(newAct) << ", A: " << myPlayer.getPokeA(newAct) 
        << ", D: " << myPlayer.getPokeD(newAct) << ", S: " << myPlayer.getPokeS(newAct) << ", M: " << myPlayer.getPokeM(newAct) << endl;
        cout << endl;
        
    }
    else
    {
        myPlayer.insertPoke(myPlayer.getNumPokemons(), wildPokemons[idx]);
        tiles[wildPokemonsX[idx]][wildPokemonsY[idx]] = "p"; // the tile that had the wild Pokemon reverts to being a plain tile again
        wildPokemons.erase(wildPokemons.begin() + idx); // the wildPokemon is erased from the vector of wild Pokemons
        wildPokemonsX.erase(wildPokemonsX.begin() + idx); // the wildPokemon's row location gets erased
        wildPokemonsY.erase(wildPokemonsY.begin() + idx); // the wildPokemon's column location gets erased
        C.erase(C.begin() + idx); 
        wF.erase(wF.begin() + idx);
    }
}

void Main::tryYourLuck()
{
    int chance = (int)(rand() % 101);
    int r = myPlayer.getRowLoc();
    int c = myPlayer.getColLoc();
    int i;
    int j;
    int k;
    vector<Pokemon> pokemonsNear;
    vector<int> positions;
    
    for(k = 0; k < wildPokemons.size(); k++)
    {
        for(i = r - 3; i <= r + 3; i++)
        {
            for(j = c - 3; j <= c + 3; j++)
            {
                if( (i == wildPokemonsX[k]) && (j == wildPokemonsY[k]) ) // loops through a 6*6 area and if it finds a wild pokemon, that pokemon gets pushed back in the vector of pokemonsNear and the positions gets pushed back with k
                {
                    pokemonsNear.push_back(wildPokemons[k]);
                    positions.push_back(k);
                }
            }
        }
    }
    
    if(pokemonsNear.size() == 0) // checks if no pokemons were found
    {
        cout << "It seems you were not lucky this time, no pokemons where found" << endl;
    }
    else if(chance < 50) // if the chance is lower than 50, then the player doesn't get the pokemon
    {
        cout << "Unlucky, couldn't catch the pokemon" << endl;
    }
    else if(chance >= 50) // if the chance is greater than or equal to 50 then the player gets the pokemon
    {
        if(myPlayer.getNumPokemons() >= 6) // if the player's roster of pokemons has 6 or more then the new pokemon joins the pokedex
        {
            pokeDex(positions[0]);
        }
        else
        {
            cout << "Oh wow, you've found " << pokemonsNear[0].getName() << " and added them to your party!" << endl;
            // string pokeName = pokemonsNear[0].getName();
            // myPlayer.setPokemons(pokeName);
            myPlayer.insertPoke(myPlayer.getNumPokemons(), pokemonsNear[0]); // the first pokemon found is the one inserted into the player's roster
            vector<string> tempTypes = pokemonsNear[0].getTypes();
            
            if(tempTypes.size() > 1)
            {
                myPlayer.setDiffTypes(tempTypes[0]);
                myPlayer.setDiffTypes(tempTypes[1]);
            }
            else
            {
                myPlayer.setDiffTypes(tempTypes[0]);
            }
            
            tiles[wildPokemonsX[positions[0]]][wildPokemonsY[positions[0]]] = "p"; // the tile that had the wild Pokemon reverts to being a plain tile again
            wildPokemons.erase(wildPokemons.begin() + positions[0]); // the wildPokemon is erased from the vector of wild Pokemons
            wildPokemonsX.erase(wildPokemonsX.begin() + positions[0]); // the wildPokemon's row location gets erased
            wildPokemonsY.erase(wildPokemonsY.begin() + positions[0]); // the wildPokemon's column location gets erased
            C.erase(C.begin() + positions[0]); 
            wF.erase(wF.begin() + positions[0]);
        }
    }
}

void Main::run(int pokeIdx, int posActivePokemon)
{
    playerC++;
    
    if(wildPokemons[pokeIdx].getS() < myPlayer.getPokeS(posActivePokemon) ) // if the speed of the wildPokemon is strictly lower than the players active pokemon speed, then player escapes
    {
         int r;
            int c;
            int closestCenter = 999999; // closestCenter is set to be a very high number
            int theR;
            int theC;
            
            for(r = 0; r < 25; r++) // loops through the whole map
            {
                for(c = 0; c < 16; c++)
                {
                    if(tiles[r][c] == "C") // checks if the tile is occupied by a Pokemon Center
                    {
                        int diffR = myPlayer.getRowLoc() - r; // gets the difference of the player's row location and the center's row location
                        int diffC = myPlayer.getColLoc() - c; // gets the difference of the player's column location and the center's column location
                        int tempDist = pow(diffR, 2) + pow(diffC, 2); // the distance between the player and the center is calculated as the difference of the row's squared + the difference of the column's squared
                        
                        if(tempDist < closestCenter) // if the temporary distance is less than the closestCenter then closestCenter becomes = to the temporary distance
                        {
                            closestCenter = tempDist;
                            theR = r; // stores the row of the closest center 
                            theC = c; // stores the column of the closest center
                        }
                        
                    }
                }
            }
            
            myPlayer.setRowLoc(theR); // the player's row gets set equal to the row of the closest Center
            myPlayer.setColLoc(theC); // the player's column gets set equal to the column of the closest Center
            playerC = 0;
            Center();
            
            quitBattle = true;
    }
    else
    {
        int B = (wildPokemons[pokeIdx].getS() / 4) % 256;
        int F = ( (myPlayer.getPokeS(posActivePokemon) * 32) / B) * playerC;
        
        int randNum = rand() % 256;
        
        if(F > 255) // if the F calculted is greater than 255 then the player escapes
        {
            int r;
            int c;
            int closestCenter = 999999;
            int theR;
            int theC;
            
            for(r = 0; r < 25; r++)
            {
                for(c = 0; c < 16; c++)
                {
                    if(tiles[r][c] == "C")
                    {
                        int diffR = myPlayer.getRowLoc() - r;
                        int diffC = myPlayer.getColLoc() - c;
                        int tempDist = pow(diffR, 2) + pow(diffC, 2);
                        
                        if(tempDist < closestCenter)
                        {
                            closestCenter = tempDist;
                            theR = r;
                            theC = c;
                        }
                        
                    }
                }
            }
            
            myPlayer.setRowLoc(theR);
            myPlayer.setColLoc(theC);
            playerC = 0;
            Center();
            
            quitBattle = true;
        }
        else if(randNum < F) // if the random number generated is less than F, the player gets to escape
        {
            int r;
            int c;
            int closestCenter = 999999;
            int theR;
            int theC;
            
            for(r = 0; r < 25; r++)
            {
                for(c = 0; c < 16; c++)
                {
                    if(tiles[r][c] == "C")
                    {
                        int diffR = myPlayer.getRowLoc() - r;
                        int diffC = myPlayer.getColLoc() - c;
                        int tempDist = pow(diffR, 2) + pow(diffC, 2);
                        
                        if(tempDist < closestCenter)
                        {
                            closestCenter = tempDist;
                            theR = r;
                            theC = c;
                        }
                        
                    }
                }
            }
            
            myPlayer.setRowLoc(theR);
            myPlayer.setColLoc(theC);
            playerC = 0;
            Center();
            
            quitBattle = true;
        }
        
    }
    
}

void Main::switchP()
{
    int counter = 0;
    int i;
    int choice;
    int OGP;
    int newAct;
    vector<int> tempIdxs;
    
    cout << "Pick another ACTIVE Pokemon: " << endl;
    cout << endl;
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getActivePoke(i) == false) && (i < 6) && (myPlayer.getPokemonHP(i) > 0 ) ) // looks for a pokemon with HP > 0 and that is not active
        {
            counter++;
            tempIdxs.push_back(i); // stores the indexs of the pokemons that the player can choose to be active
            cout << counter << ". " << myPlayer.getPokeN(i) << endl;
        }
    }
    
    cin >> choice;
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
        {
            OGP = i; // stores the current active pokemon's position
        }
    }
    
    myPlayer.changeToActive(OGP, false); // the current active pokemon becomes inactive
    myPlayer.changeToActive(tempIdxs[choice - 1], true); // the pokemon to be active becomes active
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
        {
            newAct = i;
        }
    }
    
    cout << endl;
    cout << "Your ACTIVE Pokemon is: " << endl;
    cout << "Name: " << myPlayer.getPokeN(newAct) << " (ACTIVE), " << "HP: " << myPlayer.getPokemonHP(newAct) << ", A: " << myPlayer.getPokeA(newAct)
    << ", D: " << myPlayer.getPokeD(newAct) << ", S: " << myPlayer.getPokeS(newAct) << ", M: " << myPlayer.getPokeM(newAct) << endl;
    cout << endl;
    
}

void Main::fight(int pokeIdx, int posActivePokemon)
{
    int willPokeAttack = rand() % 101;
    int i;
    bool samePos = false;
    int counter = 0;
    int tempX;
    int tempY;
    
    if( (willPokeAttack >= 60) && (wF[pokeIdx] == 0) ) // if willPokeAttack is >= 60 and the wF of the wildPokemon with index pokeIdx is 0, then the wild Pokemon decides to run away
    {
        C[pokeIdx] = C[pokeIdx] + 1; // number of attempts to run during the encounter increase by one
        int B = ((myPlayer.getPokeS(posActivePokemon)) / 4) % 256;
        int F = ( ( (wildPokemons[pokeIdx].getS() * 32) / B ) + 30 ) * C[pokeIdx];
        
        if(F > 255) // if F is greater than 255 the wildPokemon escapes
        {
            
            while(counter < 1)
            {
                tempX = rand() % 25; // generates new row location for the wild Pokemon
                tempY = rand() % 16; // generates new column location for the wild Pokemon
                
                for(i = 0; i < wildPokemonsX.size(); i++) //loops through all the location of the wildPokemons
                {
                    if(tempX == wildPokemonsX[i] && tempY == wildPokemonsY[i]) // if the newly generated location is equal to a location already occupied by a wild Pokemon then samePos becomes true
                    {
                        samePos = true;
                        break;
                    }
                }
                
                if( (tiles[tempX][tempY] == "p") && ( !((tempX == myPlayer.getRowLoc()) && (tempY == myPlayer.getColLoc()) ) ) && (samePos == false) )
                {
                    tiles[wildPokemonsX[pokeIdx]][wildPokemonsY[pokeIdx]] = "p"; // the tile that the wild Pokemon was on reverts to being a plain tile
                    wildPokemonsX[pokeIdx] = tempX; // the row location of the wild Pokemon changes to tempX
                    wildPokemonsY[pokeIdx] = tempY; // the column location of the wild Pokemon changes to tempY
                    tiles[tempX][tempY] = "Z"; // the tile that the wild Pokemon teleports to becomes a wildPokemon tile represented by Z
                    C[pokeIdx] = 0; // number of times the wild Pokemon tries to escape become 0 again
                    counter++;
                    cout << wildPokemons[pokeIdx].getName() << " has fleed the scene!" << endl;
                    quitBattle = true;
                }   
        
                samePos = false;
                
            }
        }
        else
        {
            int num = rand() % 256;
                
            if(num < F) // if the random number generated is less than F then the wild Pokemon escapes
            {
                while(counter < 1)
                {
                    tempX = rand() % 25;
                    tempY = rand() % 16;
                    
                    for(i = 0; i < wildPokemonsX.size(); i++)
                    {
                        if(tempX == wildPokemonsX[i] && tempY == wildPokemonsY[i])
                        {
                            samePos = true;
                            break;
                        }
                    }
                    
                    if( (tiles[tempX][tempY] == "p") && ( !((tempX == myPlayer.getRowLoc()) && (tempY == myPlayer.getColLoc()) ) ) && (samePos == false) )
                    {
                        tiles[wildPokemonsX[pokeIdx]][wildPokemonsY[pokeIdx]] = "p";
                        wildPokemonsX[pokeIdx] = tempX;
                        wildPokemonsY[pokeIdx] = tempY;
                        tiles[tempX][tempY] = "Z";
                        C[pokeIdx] = 0;
                        counter++;
                        cout << "The pokemon has fleed the scene!" << endl;
                        quitBattle = true;
                    }   
            
                    samePos = false;
                    
                }       
            }
            else // if the wild Pokemon fails to escapes it joins the player's roster
            {
                if(myPlayer.getNumPokemons() >= 6) // the number of pokemons in the player's roster is greater than or equal to 6 then the wild Pokemon joins the pokeDex
                {
                    pokeDex(pokeIdx);
                    
                    quitBattle = true;
                }
                else
                {
                    //myPlayer.setPokemons(wildPokemons[pokeIdx].getName());
                    myPlayer.insertPoke(myPlayer.getNumPokemons(), wildPokemons[pokeIdx]);
                    tiles[wildPokemonsX[pokeIdx]][wildPokemonsY[pokeIdx]] = "p";
                    wildPokemons.erase(wildPokemons.begin() + pokeIdx);
                    wildPokemonsX.erase(wildPokemonsX.begin() + pokeIdx);
                    wildPokemonsY.erase(wildPokemonsY.begin() + pokeIdx);
                    C.erase(C.begin() + pokeIdx);
                    wF.erase(wF.begin() + pokeIdx);
                    cout << "The pokemon has tried to flee but it failed and now it belongs to you! " << endl;
                    quitBattle = true;
                }
            }
        }
    }
    else
    {
        wF[pokeIdx] = 1;
        
        if(myPlayer.getPokeS(posActivePokemon) > wildPokemons[pokeIdx].getS())
        {
            int playerAttack = rand() % myPlayer.getPokeA(posActivePokemon) + 1; // generates random attack value for player's pokemon
            int pokeAttack = rand() % wildPokemons[pokeIdx].getA() + 1; // generates random attack value for wild Pokemon
            int playerDef = rand() % myPlayer.getPokeD(posActivePokemon) + 1; // generates random defense value for the player's pokemon
            int pokeDef = rand() % wildPokemons[pokeIdx].getD() + 1; // generates random defense value for wild Pokemon
            
            if(playerAttack > pokeDef) //checks if the player's pokemon attack value is greater than the wild Pokemon's defense value
            {
                int DamP = (playerAttack - pokeDef) * -1; // damage done by pokemon is the playerAttack - pokeDef
                wildPokemons[pokeIdx].changeHP(DamP);
                
                cout << myPlayer.getPokeN(posActivePokemon) << " attacks first " << endl;
                cout << myPlayer.getPokeN(posActivePokemon) << " deals " << DamP * -1 << " damage" << endl;
                
                cout << "Name: " << wildPokemons[pokeIdx].getName() << " Level: " << wildPokemons[pokeIdx].getLevel() << ", HP: " << wildPokemons[pokeIdx].getHP() << ", A: " << wildPokemons[pokeIdx].getA()
                << ", D: " << wildPokemons[pokeIdx].getD() << ", S: " << wildPokemons[pokeIdx].getS() << ", M: " << wildPokemons[pokeIdx].getM() << endl;
                
                cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
                << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
                cout << endl;
            }
            
            if(pokeAttack > playerDef) // checks if the wild Pokemon's attack value is greater than the player's pokemon's defense value
            {
                int DamPo = (pokeAttack - playerDef) * -1; // damage done is pokeAttack - playerDef
                myPlayer.changePokeHP(posActivePokemon, DamPo);
                
                cout << wildPokemons[pokeIdx].getName() << " attacks second " << endl;
                cout << wildPokemons[pokeIdx].getName() << " deals " << DamPo * -1 << " damage" << endl;
                
                cout << "Name: " << wildPokemons[pokeIdx].getName() << " Level: " << wildPokemons[pokeIdx].getLevel() << ", HP: " << wildPokemons[pokeIdx].getHP() << ", A: " << wildPokemons[pokeIdx].getA()
                << ", D: " << wildPokemons[pokeIdx].getD() << ", S: " << wildPokemons[pokeIdx].getS() << ", M: " << wildPokemons[pokeIdx].getM() << endl;
                
                cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
                << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
                cout << endl;
            }
            
            if( (pokeAttack < playerDef) && (playerAttack < pokeDef) ) // checks if neither pokemons did any damage
            {
                cout << "No pokemon did any damage" << endl;
            }
        }
        else
        {
            int pA = rand() % myPlayer.getPokeA(posActivePokemon) + 1; // generates random attack value for player's pokemon
            int wA = rand() % wildPokemons[pokeIdx].getA() + 1; // generates random attack value for wild Pokemon
            int pD = rand() % myPlayer.getPokeD(posActivePokemon) + 1; // generates random defense value for player's pokemon
            int wD = rand() % wildPokemons[pokeIdx].getD() + 1; // generates random defense value for wild Pokemon
            
            if(wA > pD)
            {
                int dW = (wA - pD) * -1;
                myPlayer.changePokeHP(posActivePokemon, dW);
                
                cout << wildPokemons[pokeIdx].getName() << " attacks first " << endl;
                cout << wildPokemons[pokeIdx].getName() << " deals " << dW * -1 << " damage" << endl;
                
                cout << "Name: " << wildPokemons[pokeIdx].getName() << " Level: " << wildPokemons[pokeIdx].getLevel() << ", HP: " << wildPokemons[pokeIdx].getHP() << ", A: " << wildPokemons[pokeIdx].getA()
                << ", D: " << wildPokemons[pokeIdx].getD() << ", S: " << wildPokemons[pokeIdx].getS() << ", M: " << wildPokemons[pokeIdx].getM() << endl;
                
                cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
                << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
                cout << endl;
            }
            
            if(pA > wD)
            {
                int dP = (pA - wD) * -1;
                wildPokemons[pokeIdx].changeHP(dP);
                
                cout << myPlayer.getPokeN(posActivePokemon) << " attacks second " << endl;
                cout << myPlayer.getPokeN(posActivePokemon) << " deals " << dP * -1 << " damage" << endl;
                
                cout << "Name: " << wildPokemons[pokeIdx].getName() << " Level: " << wildPokemons[pokeIdx].getLevel() << ", HP: " << wildPokemons[pokeIdx].getHP() << ", A: " << wildPokemons[pokeIdx].getA()
                << ", D: " << wildPokemons[pokeIdx].getD() << ", S: " << wildPokemons[pokeIdx].getS() << ", M: " << wildPokemons[pokeIdx].getM() << endl;
                
                cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
                << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
                cout << endl;
            }
            
            if( (pA < wD) && (wA < pD) )
            {
                cout << "No pokemon did any damage" << endl;
            }
        }
        
        if(wildPokemons[pokeIdx].getHP() <= 0) // if the wild Pokemon faints then it joins the players party
        {
            levelPlayerPoke(posActivePokemon); // the player's active pokemon levels up
            
            if(myPlayer.getNumPokemons() >= 6) 
            {
                int MxH = wildPokemons[pokeIdx].getMaxHP();
                wildPokemons[pokeIdx].setHP(MxH); // the wild Pokemon's health gets fully restored
                
                pokeDex(pokeIdx);
                
                quitBattle = true;
            }
            else
            {
                int WMP = wildPokemons[pokeIdx].getMaxHP();
                wildPokemons[pokeIdx].setHP(WMP); // the wild Pokemon's health gets fully restored
                // string tempName = wildPokemons[pokeIdx].getName();
                // myPlayer.setPokemons(tempName);
                myPlayer.insertPoke(myPlayer.getNumPokemons(), wildPokemons[pokeIdx]);
                tiles[wildPokemonsX[pokeIdx]][wildPokemonsY[pokeIdx]] = "p";
                wildPokemons.erase(wildPokemons.begin() + pokeIdx);
                wildPokemonsX.erase(wildPokemonsX.begin() + pokeIdx);
                wildPokemonsY.erase(wildPokemonsY.begin() + pokeIdx);
                C.erase(C.begin() + pokeIdx);
                wF.erase(wF.begin() + pokeIdx);
                quitBattle = true;
            }
        }
        
        int faints = 0;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            if( (myPlayer.getPokemonHP(i) <= 0) && (i < 6))
            {
                faints++;
            }
        }
        
        if( (myPlayer.getPokemonHP(posActivePokemon) <= 0) && (faints < 6) ) //checks if the player's pokemon fainted
        {
            levelUp(pokeIdx); // the wild Pokemon levels up
            myPlayer.changePokeF(posActivePokemon, true); // the player's active pokemon gets set to be a faint 
            
            for(i = 0; i < myPlayer.getNumPokemons(); i++)
            {
                if( (i != posActivePokemon) && (i < 6) && (myPlayer.getPokeF(i) == false) )
                {
                    myPlayer.changeToActive(i, true); // sets the next pokemon that is not a faint to be the new active pokemon
                    break;
                }
            }
            
            myPlayer.changeToActive(posActivePokemon, false);
            
            
        }
        
        if( (faints == 6) || (faints == myPlayer.getNumPokemons()) ) // if all player's active party pokemons are faints then the player teleports to the nearest center
        {
            levelUp(pokeIdx); // the wild Pokemon levels Up
            
            int r;
            int c;
            int closestCenter = 999999;
            int theR;
            int theC;
            
            for(r = 0; r < 25; r++)
            {
                for(c = 0; c < 16; c++)
                {
                    if(tiles[r][c] == "C")
                    {
                        int diffR = myPlayer.getRowLoc() - r;
                        int diffC = myPlayer.getColLoc() - c;
                        int tempDist = pow(diffR, 2) + pow(diffC, 2);
                        
                        if(tempDist < closestCenter)
                        {
                            closestCenter = tempDist;
                            theR = r;
                            theC = c;
                        }
                        
                    }
                }
            }
            
            myPlayer.setRowLoc(theR);
            myPlayer.setColLoc(theC);
            Center();
            
            quitBattle = true;
        }
        
    }
}

void Main::battle(int pokeIdx)
{
    Encounters++;
    cout << "You ran into a wild Pokemon! " << endl;
    cout << "Name: " << wildPokemons[pokeIdx].getName() << " Level: " << wildPokemons[pokeIdx].getLevel() << ", HP: " << wildPokemons[pokeIdx].getHP() << ", A: " << wildPokemons[pokeIdx].getA() << ", D: " << wildPokemons[pokeIdx].getD()
    << ", S: " << wildPokemons[pokeIdx].getS() << ", M: " << wildPokemons[pokeIdx].getM() << endl;
    cout << endl;
    
    int posActivePokemon;
    int i;
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
        {
            posActivePokemon = i;
        }
    }
    
    cout << "Your ACTIVE Pokemon is: " << endl;
    cout << "Name " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon) 
    << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
    cout << endl;
    
    if(Encounters <= 2) // if it is the first 2 encounters with a wild Pokemon then the wild Pokemon joins the player's party
    {
        if(myPlayer.getNumPokemons() >= 6) // if the player's roster is greater than or equal to 6 then the wild Pokemon joins the pokeDex
        {
            pokeDex(pokeIdx);
        }
        else
        {
            cout << "This is your " << Encounters << " encounters, the wild pokemon " << wildPokemons[pokeIdx].getName() << " joins your party!" << endl;
            cout << endl;
            //myPlayer.setPokemons(wildPokemons[pokeIdx].getName());
            myPlayer.insertPoke(myPlayer.getNumPokemons(), wildPokemons[pokeIdx]);
            tiles[wildPokemonsX[pokeIdx]][wildPokemonsY[pokeIdx]] = "p";
            wildPokemons.erase(wildPokemons.begin() + pokeIdx);
            wildPokemonsX.erase(wildPokemonsX.begin() + pokeIdx);
            wildPokemonsY.erase(wildPokemonsY.begin() + pokeIdx);
            C.erase(C.begin() + pokeIdx);
            wF.erase(wF.begin() + pokeIdx);
        }
    }
    else if(Encounters > 2) 
    {
        int choice;
        
        while(quitBattle == false)
        {
            bool noHealthyPoke = false;
            int countUnHealthy = 0;
            
            for(i = 0; i < myPlayer.getNumPokemons(); i++)
            {
                if( (myPlayer.getActivePoke(i) == true) && (i < 6) && (myPlayer.getPokemonHP(i) > 0))
                {
                    posActivePokemon = i; // stores the player's current active pokemon
                }
            }
                
            for(i = 0; i < myPlayer.getNumPokemons(); i++)
            {
                if( (myPlayer.getPokemonHP(i) <= 0 ) && (i < 6) )
                {
                    countUnHealthy++;
                }
            }
            
            if(countUnHealthy >= 6)
            {
                noHealthyPoke = true;
            }
            
            cout << "What do you want to do (pick 1, 2, or 3): " << endl;
            cout << "1. Fight" << endl;
            cout << "2. Switch Active Pokemon" << endl;
            cout << "3. Run" << endl;
            cout << endl;
            cin >> choice; 
            
            if(choice == 1)
            {
                if(noHealthyPoke == true) // checks if all the pokemon in the player's active party are faints 
                {
                    cout << "Non of the pokemons in your party are healthy enough to fight, please go to the nearest Pokemon center." << endl;
                    quitBattle = true;
                }
                else
                {
                    fight(pokeIdx, posActivePokemon);
                }
            }
            else if(choice == 2)
            {
                switchP();
            }
            else if(choice == 3)
            {
                run(pokeIdx, posActivePokemon);
            }
            else
            {
                cout << "Invalid option " << endl;
            }
        }
    }
}

void Main::Center()
{
    cout << endl;
    printMap();
    cout << endl;
    
    int i;
    char answer;
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        int tempHP = myPlayer.getMaxPokemonHP(i);
        myPlayer.healPoke(i, tempHP); // restores the pokemons HP back to full
    }
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        cout << "Name: " << myPlayer.getPokeN(i) <<  ", HP: " << myPlayer.getPokemonHP(i) << endl; 
    }
    
    cout << endl;
    
    cout << "Welcome to the Pokemon Center. All Pokemon in your party have been healed. Do you want to change members of your party (Y/N): " << endl;
    cin >> answer;
    
    if(answer == 'Y')
    {
        if(myPlayer.getNumPokemons() <= 6) // if the player has no pokemons in their pokeDex they have to go out of the pokemon Center
        {
            cout << "You have no pokemons in your pokedex right now!" << endl;
            cout << endl;
            printMap();
            cout << endl;
            char dir = travelChoice();
            travel(dir, myPlayer, tiles);
            printMap();
            cout << endl;
        }
        else
        {
            string line;
            vector<int> tempIdxs;
            int counter = 0;
            int choice;
            
            cout << "Here are all the Pokemon in your Pokedex. Choose at most 6 numbers, followed by Q for quit: " << endl;
            cout << "Please enter each input followed by space and after Q press enter! Example: 1 2 3 Q" << endl;
            
            for(i = 6; i < myPlayer.getNumPokemons(); i++)
            {
                counter++;
                cout << counter << ". " << myPlayer.getPokeN(i) << endl;
            }
            
            cin.ignore();
            getline(cin, line);
            
            int numPokesChosen = (line.size() - 1) / 2;
            
            for(i = 0; i < line.size(); i++)
            {
                if( (i != (line.size() - 1) ) && (i % 2 == 0) )
                {
                    int idx = 6 + ( stoi(line.substr(i, 1)) - 1); 
                    tempIdxs.push_back(idx); // stores the indexs of the pokemons chosen
                }
            }
            
            int numbers = 0;
            
            cout << "You have chosen the " << numPokesChosen << " Pokemon below. Please choose which one should be the ACTIVE Pokemon: " << endl;
            cout << endl;
            
            for(i = 0; i < numPokesChosen; i++)
            {
                numbers++;
                cout << numbers << ". " << myPlayer.getPokeN(tempIdxs[i]) << endl;
            }
            
            cin >> choice;
            
            int posNewA = tempIdxs[choice - 1]; // stores the position of the pokemon to be active
            int posOldA; // stores the position of the current active pokemon
            
            for(i = 0; i < myPlayer.getNumPokemons(); i++)
            {
                if(myPlayer.getActivePoke(i) == true)
                {
                    posOldA = i;
                    break;
                }
            }
            
            myPlayer.changeToActive(posOldA,  false);
            myPlayer.changeToActive(posNewA, true);
            
            int currA;
            
            for(i = 0; i < myPlayer.getNumPokemons(); i++)
            {
                if(myPlayer.getActivePoke(i) == true)
                {
                    currA = i;
                }
            }
            
            cout << endl;
            cout << "Your ACTIVE Pokemon is: " << endl;
            cout << "Name: " << myPlayer.getPokeN(currA) << " (ACTIVE), HP: " << myPlayer.getPokemonHP(currA) << ", A: " << myPlayer.getPokeA(currA)
            << ", D: " << myPlayer.getPokeD(currA) << ", S: " << myPlayer.getPokeS(currA) << ", M: " << myPlayer.getPokeM(currA) << endl;
            cout << endl;
            
            printMap();
            cout << endl;
            char di = travelChoice();
            travel(di, myPlayer, tiles);
            printMap();
            cout << endl;
            
        }
        
    }
    else if(answer == 'N')
    {
        printMap();
        cout << endl;
        char dir = travelChoice();
        travel(dir, myPlayer, tiles);
        printMap();
        cout << endl;
    }
}

void Main::fightTrainers(int trainerIdx, int posActivePokemon, int trainerActivePoke)
{
    int i;
    
    if(myPlayer.getPokeS(posActivePokemon) > trainers[trainerIdx].getPokeSp(trainerActivePoke))
    {
        int playerAttack = rand() % myPlayer.getPokeA(posActivePokemon) + 1;
        int pokeAttack = rand() % trainers[trainerIdx].getPokeAt(trainerActivePoke) + 1;
        int playerDef = rand() % myPlayer.getPokeD(posActivePokemon) + 1;
        int pokeDef = rand() % trainers[trainerIdx].getPokeDef(trainerActivePoke) + 1;
            
        if(playerAttack > pokeDef)
        {
            int DamP = (playerAttack - pokeDef) * -1;
            trainers[trainerIdx].changeMyPokeHP(trainerActivePoke ,DamP);
                
            cout << myPlayer.getPokeN(posActivePokemon) << " attacks first " << endl;
            cout << myPlayer.getPokeN(posActivePokemon) << " deals " << DamP * -1 << " damage" << endl;
                
            cout << "Name: " << trainers[trainerIdx].getPokeName(trainerActivePoke) << " Level: " << trainers[trainerIdx].getPokeLv(trainerActivePoke) << ", HP: " << trainers[trainerIdx].getPokeHP(trainerActivePoke) << ", A: " << trainers[trainerIdx].getPokeAt(trainerActivePoke)
            << ", D: " << trainers[trainerIdx].getPokeDef(trainerActivePoke) << ", S: " << trainers[trainerIdx].getPokeSp(trainerActivePoke) << ", M: " << trainers[trainerIdx].getPokeMx(trainerActivePoke) << endl;
                
            cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
            << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
            cout << endl;
        }
            
        if(pokeAttack > playerDef)
        {
            int DamPo = (pokeAttack - playerDef) * -1;
            myPlayer.changePokeHP(posActivePokemon, DamPo);
                
            cout << trainers[trainerIdx].getPokeName(trainerActivePoke) << " attacks second " << endl;
            cout << trainers[trainerIdx].getPokeName(trainerActivePoke) << " deals " << DamPo * -1 << " damage" << endl;
                
            cout << "Name: " << trainers[trainerIdx].getPokeName(trainerActivePoke) << " Level: " << trainers[trainerIdx].getPokeLv(trainerActivePoke) << ", HP: " << trainers[trainerIdx].getPokeHP(trainerActivePoke) << ", A: " << trainers[trainerIdx].getPokeAt(trainerActivePoke)
            << ", D: " << trainers[trainerIdx].getPokeDef(trainerActivePoke) << ", S: " << trainers[trainerIdx].getPokeSp(trainerActivePoke) << ", M: " << trainers[trainerIdx].getPokeMx(trainerActivePoke) << endl;
                
            cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
            << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
            cout << endl;
        }
        
        if( (pokeAttack <  playerDef) && (playerAttack < pokeDef) )
        {
            cout << "No pokemon did any damage" << endl;
        }
    }
    else
    {
        int pA = rand() % myPlayer.getPokeA(posActivePokemon) + 1;
        int wA = rand() % trainers[trainerIdx].getPokeAt(trainerActivePoke) + 1;
        int pD = rand() % myPlayer.getPokeD(posActivePokemon) + 1;
        int wD = rand() % trainers[trainerIdx].getPokeDef(trainerActivePoke) + 1;
        
        if(wA > pD)
        {
            int dW = (wA - pD) * -1;
            myPlayer.changePokeHP(posActivePokemon, dW);
                
            cout << trainers[trainerIdx].getPokeName(trainerActivePoke) << " attacks first " << endl;
            cout << trainers[trainerIdx].getPokeName(trainerActivePoke) << " deals " << dW * -1 << " damage" << endl;
                
            cout << "Name: " << trainers[trainerIdx].getPokeName(trainerActivePoke) << " Level: " << trainers[trainerIdx].getPokeLv(trainerActivePoke) << ", HP: " << trainers[trainerIdx].getPokeHP(trainerActivePoke) << ", A: " << trainers[trainerIdx].getPokeAt(trainerActivePoke)
            << ", D: " << trainers[trainerIdx].getPokeDef(trainerActivePoke) << ", S: " << trainers[trainerIdx].getPokeSp(trainerActivePoke) << ", M: " << trainers[trainerIdx].getPokeMx(trainerActivePoke) << endl;
                
            cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
            << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
            cout << endl;
        }
            
        if(pA > wD)
        {
            int dP = (pA - wD) * -1;
            trainers[trainerIdx].changeMyPokeHP(trainerActivePoke ,dP);
                
            cout << myPlayer.getPokeN(posActivePokemon) << " attacks second " << endl;
            cout << myPlayer.getPokeN(posActivePokemon) << " deals " << dP * -1 << " damage" << endl;
                
            cout << "Name: " << trainers[trainerIdx].getPokeName(trainerActivePoke) << " Level: " << trainers[trainerIdx].getPokeLv(trainerActivePoke) << ", HP: " << trainers[trainerIdx].getPokeHP(trainerActivePoke) << ", A: " << trainers[trainerIdx].getPokeAt(trainerActivePoke)
            << ", D: " << trainers[trainerIdx].getPokeDef(trainerActivePoke) << ", S: " << trainers[trainerIdx].getPokeSp(trainerActivePoke) << ", M: " << trainers[trainerIdx].getPokeMx(trainerActivePoke) << endl;
                
            cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
            << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
            cout << endl;
        }
        
        if( (pA < wD) && (wA < pD) )
        {
            cout << "No pokemon did any damage" << endl;
        }
    }
    
    int trainerFaints = 0;
    int playerFaints = 0;
    int trainerPokemons = trainers[trainerIdx].getNumPokemons();
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getPokemonHP(i) <= 0) && (i < 6) )
        {
            playerFaints++;
        }
    }
    
    for(i = 0; i < trainers[trainerIdx].getNumPokemons(); i++)
    {
        if(trainers[trainerIdx].getPokeHP(i) <= 0 )
        {
            trainerFaints++;
        }
    }
    
    if( (myPlayer.getPokemonHP(posActivePokemon) <= 0) && (playerFaints < 6) )
    {
        myPlayer.changePokeF(posActivePokemon, true);
            
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            if( (i != posActivePokemon) && (i < 6) && (myPlayer.getPokeF(i) == false) )
            {
                myPlayer.changeToActive(i, true);
                break;
            }
        }
            
        myPlayer.changeToActive(posActivePokemon, false);
            
    }
    
    
    if( (playerFaints == 6) || (playerFaints == myPlayer.getNumPokemons()) ) // if the all the player's active party pokemon are faints then the player teleports to the nearest pokemon Center
    {
           levelTrainerPoke(trainerIdx, trainerActivePoke); // the trainers active pokemon levels up
            
            int r;
            int c;
            int closestCenter = 999999;
            int theR;
            int theC;
            
            for(r = 0; r < 25; r++)
            {
                for(c = 0; c < 16; c++)
                {
                    if(tiles[r][c] == "C")
                    {
                        int diffR = myPlayer.getRowLoc() - r;
                        int diffC = myPlayer.getColLoc() - c;
                        int tempDist = pow(diffR, 2) + pow(diffC, 2);
                        
                        if(tempDist < closestCenter)
                        {
                            closestCenter = tempDist;
                            theR = r;
                            theC = c;
                        }
                        
                    }
                }
            }
            
            myPlayer.setRowLoc(theR);
            myPlayer.setColLoc(theC);
            Center();
            
            quitTrainerBattle = true;
    }
    else if(trainerFaints == trainerPokemons ) //checks if all the trainers pokemons are faints, if so the player wins 
    {
        levelPlayerPoke(posActivePokemon); // the player's active pokemon levels up
        
        myPlayer.addBadge(1); 
        myPlayer.addPokeBall(5);
        myPlayer.addPoints(60);
        
        for(i = 0; i < trainers[trainerIdx].getNumPokemons(); i++)
        {
            // string tempName = trainers[trainerIdx].getPokeName(i);
            // myPlayer.setPokemons(tempName);
            Pokemon tempPoke = trainers[trainerIdx].getPokemon(i);
            myPlayer.insertPoke(myPlayer.getNumPokemons() ,tempPoke); // the trainers pokemons joins the player's roster
        }
        
        trainers.erase(trainers.begin() + trainerIdx); // the trainer is erased from the vector of trainers
        
        cout << "You have won you earned 1 badge, 5 pokeballs, and 60 points: " << endl;
        cout << "Pokeballs: " << myPlayer.getPokeBalls() << endl;
        cout << "Badges: " << myPlayer.getBadges() << endl;
        cout << "Points: " << myPlayer.getPoints() << endl;
        cout << "Your Pokemons: " << endl;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            cout << "Name: " << myPlayer.getPokeN(i) << endl;
        }
        cout << endl;
        
        printMap();
        cout << endl;
        char dir = travelChoice();
        travel(dir, myPlayer, tiles);
        printMap();
        cout << endl;
        
        quitTrainerBattle = true;
    }
    
}

void Main::trainerEncounters()
{
    int randTrainer = rand() % trainers.size();
    int i;
    int posTrainerActivePoke;
    int posActivePokemon;
    
    for(i = 0; i < trainers[randTrainer].getNumPokemons(); i++)
    {
        if( trainers[randTrainer].getPokeHP(i) > 0)
        {
            posTrainerActivePoke = i;
            break;
        }
    }
    
    for(i = 0; i < myPlayer.getNumPokemons(); i++)
    {
        if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
        {
            posActivePokemon = i;
            break;
        }
    }
    
    cout << endl;
    cout << "You arrived at the Gym and the trainer is there. She wants to fight.\nHer ACTIVE Pokemon is: " << endl;
    cout << "Name: " << trainers[randTrainer].getPokeName(posTrainerActivePoke) << " Level: " << trainers[randTrainer].getPokeLv(posTrainerActivePoke) << ", HP: " << trainers[randTrainer].getPokeHP(posTrainerActivePoke)
    << ", A: " << trainers[randTrainer].getPokeAt(posTrainerActivePoke) << ", D: " << trainers[randTrainer].getPokeDef(posTrainerActivePoke)
    << ", S: " << trainers[randTrainer].getPokeSp(posTrainerActivePoke) << ", M: " << trainers[randTrainer].getPokeMx(posTrainerActivePoke) << endl;
    
    cout << endl;
    cout << "Your ACTIVE Pokemon is: " << endl;
    cout << "Name: " << myPlayer.getPokeN(posActivePokemon) << " Level: " << myPlayer.getPokeL(posActivePokemon) << ", HP: " << myPlayer.getPokemonHP(posActivePokemon) << ", A: " << myPlayer.getPokeA(posActivePokemon)
    << ", D: " << myPlayer.getPokeD(posActivePokemon) << ", S: " << myPlayer.getPokeS(posActivePokemon) << ", M: " << myPlayer.getPokeM(posActivePokemon) << endl;
    cout << endl;
    
    while(quitTrainerBattle == false)
    {
        int choice;
        
        for(i = 0; i < myPlayer.getNumPokemons(); i++)
        {
            if( (myPlayer.getActivePoke(i) == true) && (i < 6) )
            {
                posActivePokemon = i; // stores the positon of the players active pokemon
                break;
            }
        }
        
        for(i = 0; i < trainers[randTrainer].getNumPokemons(); i++)
        {
            if( trainers[randTrainer].getPokeHP(i) > 0)
            {
                posTrainerActivePoke = i; // stores the position of the first pokemon that has HP greater than 0
                break;
            }
        }
        
        cout << "What dou you want to do (1 or 2): " << endl;
        cout << "1. Fight" << endl;
        cout << "2. Switch Active Pokemon" << endl;
        cout << endl;
        
        cin >> choice;
        
        if(choice == 1)
        {
            fightTrainers(randTrainer, posActivePokemon, posTrainerActivePoke);
        }
        else if(choice == 2)
        {
            switchP();
        }
        else
        {
            cout << "Invalid option " << endl;
        }
        
    }
    
}

void Main::yourTurn()
{
    bool quit = false;
    int j;
    int k;
    int x;
    
    // for(x = 0; x < wildPokemons.size(); x++)
    // {
    //     for(j = playerRow - 2; j <= playerRow + 2; j++)
    //     {
    //         for(k = playerCol - 2; k <= playerCol + 2; k++)
    //         {
    //             if( (j == wildPokemonsX[x]) && (k == wildPokemonsY[x]) )
    //             {
    //                 battle(x);
    //             }
    //         }
    //     }
    // }
    
    while(quit == false) // loops until player wins or decides to quit the game
    {
        
        if(myPlayer.getBadges() >= 6) // checks if the number of badges the player has earned are 6 or more, if so the player wins the game
        {
            playerWins();
            quit = true;
        }
        else
        {
            int playerRow = myPlayer.getRowLoc();
            int playerCol = myPlayer.getColLoc();
            quitBattle = false;
            quitTrainerBattle = false;
            
            for(x = 0; x < wildPokemons.size(); x++) // loops through a 6*6 area centered at the player
            {
                for(j = playerRow - 2; j <= playerRow + 2; j++)
                {
                    for(k = playerCol - 2; k <= playerCol + 2; k++)
                    {
                        if( (tiles[j][k] == "C") && (myPlayer.getRowLoc() == j) && (myPlayer.getColLoc() == k) ) // tile is a Pokemon center and the player is in it then calls the Center function
                        {
                            Center();
                        }
                        else if( (j == wildPokemonsX[x]) && (k == wildPokemonsY[x]) ) // if there is a wild Pokemon in the 6*6 area then calls battle function
                        {
                            battle(x);
                        }
                        else if( (tiles[j][k] == "G") && (myPlayer.getRowLoc() == j) && (myPlayer.getColLoc() == k) ) // if the tile is a Pokemon gym and the player is in it then it calls the trainerEncounters function
                        {
                            trainerEncounters();
                        }
                    }
                }
            }
            
            cout << "The sun is shining, " << myPlayer.getPlayerName() << "! It's a beautiful day,\nwe have " << myPlayer.getPokeBalls() << " Pokeballs left and your Pokemon are strong." << endl;
            
            int numPoke = myPlayer.getNumPokemons();
            
            int i;
            int choice;
            char di;
            
            vector<Pokemon> tempPokemons;
            
            tempPokemons = myPlayer.getPokemons();
            
            for(i = 0; i < numPoke; i++)
            {
                if( (i < 6) ) // && (tempPokemons[i].getActive() == true)
                {   
                    cout << tempPokemons[i].getName() << "(Active) " << "Level: " << tempPokemons[i].getLevel() << ", HP: " << tempPokemons[i].getHP()
                    << ", A: " << tempPokemons[i].getA() << ", D: " << tempPokemons[i].getD() << ", S: " << tempPokemons[i].getS() << ", M: " << tempPokemons[i].getM() << endl;
                }
            }
        
        // cout << endl;    
        // cout << "Player's pokemon: " << endl;
        // for(i = 0; i < tempPokemons.size(); i++)
        // {
        //     cout << tempPokemons[i].getName() << endl;
        // }
        
        // cout << endl;
        // cout << "allPokemons: " << endl;
        // for(i = 0; i < allPokemons.size(); i++)
        // {
        //     cout << allPokemons[i].getName() << endl;
        // }
        
        // cout << endl;
        // cout << "WildPokemons: " << endl;
        // for(i = 0; i < wildPokemons.size(); i++)
        // {
        //     cout << wildPokemons[i].getName() << endl;
        // }
        
        // cout << endl;
        // int x;
        
        // for(x = 0; x < 15; x++)
        // {
            
        //     vector<Pokemon> tempTrainerP;
        //     tempTrainerP = trainers[x].getPokes();
            
        //     cout << "Trainer " << x << "'s pokemons: " << endl;
        //     for(i = 0; i < tempTrainerP.size(); i++)
        //     {
        //         cout << tempTrainerP[i].getName() << endl;
        //     }
        //     cout << endl;
            
        // }
        
        // cout << endl;
        // cout << "WildPokemons locations: " << endl;
        
        // for(i = 0; i < 20; i++)
        // {
        //     cout << "Pokemon " << i << " row: " << wildPokemonsX[i] << " column: " << wildPokemonsY[i] << endl;
        // }
            
            cout << endl;
           
            cout << "Please choose from the following options: " << endl;
            cout << "1. Travel" << endl;
            cout << "2. Rest" << endl;
            cout << "3. Try your luck" << endl;
            cout << "4. Quit the game" << endl;
            
            cin >> choice;
            
            if(choice == 1)
            {
                printMap();
                cout << endl;
                di = travelChoice();
                travel(di, myPlayer, tiles);
                printMap();
            }
            else if(choice == 2)
            {
                rest(myPlayer);
            }
            else if(choice == 3)
            {
                tryYourLuck();
            }
            else if(choice == 4)
            {
                quit = true;
                quitGame();
            }
            else
            {
                cout << "Invalid option" << endl;
            }
        }
    }
}

void Main::readPokemons()
{
    ifstream in_file;
    in_file.open("pokemon.txt");
    string tempLine[9];
    string line;
    int numSplits;
    vector<int> idxs;
    int tempX;
    int tempY;
    vector<Pokemon> playerPokemon = myPlayer.getPokemons();
    int playerPokePos = playerPokemon[0].getIndex(); // stores the players starting pokemons index
    bool sameIdx = false;
    srand(time(0));
    int i;
    int counter = 0;
    Pokemon tempPokemon;
    
    while(getline(in_file, line))
    {
        numSplits = splitMain(line, ',', tempLine, 9);
            
        if(tempLine[0] != "#")
        {
            tempPokemon.setIndex( stoi(tempLine[0]) - 1);
            tempPokemon.setName(tempLine[1]);
            tempPokemon.setHP( stoi(tempLine[2]) );
            tempPokemon.setMaxHP( stoi(tempLine[2]) );
            tempPokemon.setA( stoi(tempLine[3]) );
            tempPokemon.setD( stoi(tempLine[4]) );
            tempPokemon.setS( stoi(tempLine[5]) );
            tempPokemon.setMax( stoi(tempLine[6]) );
                
            if(numSplits > 8)
            {
                tempPokemon.setTypes(tempLine[7]);
                tempPokemon.setTypes(tempLine[8]);
            }
            else
            {
                tempPokemon.setTypes(tempLine[7]);
            }
                
            allPokemons.push_back(tempPokemon); // the temporary pokemon gets pushed back into the allPokemons vector
            
        }
    }
    
    allPokemons.erase(allPokemons.begin() + playerPokePos); // erases the player's starting pokemon from allPokemons vector
    
    while(counter < 20) // loops until 20 random wildPokemons have been generated 
    {
        int a = rand() % 150;
        
        if(idxs.size() == 0)
        {
            idxs.push_back(a);
            counter++;
        }
        else
        {
            for(i = 0; i < idxs.size(); i++) // loops through all the indexs generated so far
            {
                if(a == idxs[i]) // if the new index already occurs in the vector then sameIdx becomes true
                {
                    sameIdx = true;
                }
            }
            
            if(sameIdx == false) // if the sameIdx is false the new index gets pushed back into the vector idxs 
            {
                idxs.push_back(a);
                counter++;
            }
        }
        
        sameIdx = false;
    }
    
    bool samePos = false;
    
    while( wildPokemonsX.size() < 20 && wildPokemonsY.size() < 20)
    {
        tempX = (int)(rand() % 25); // generates random row for wildPokemon
        tempY = (int)(rand() % 16); // generates random column for wildPokemon
        
        for(i = 0; i < wildPokemonsX.size(); i++) // loops through all the wild Pokemons rows and columns
        {
            if(tempX == wildPokemonsX[i] && tempY == wildPokemonsY[i]) // if the new row and column occur already in the wildPokemons locations then samePos becomes true
            {
                samePos = true;
                break;
            }
        }
        
        if( (tiles[tempX][tempY] == "p") && ( !((tempX == myPlayer.getRowLoc()) && (tempY == myPlayer.getColLoc()) ) ) && (samePos == false) ) // checks if the tile is plain and the position is not the same as the player's position
        {
            wildPokemonsX.push_back(tempX); 
            wildPokemonsY.push_back(tempY);
            tiles[tempX][tempY] = "Z"; // the tile becomes a wild Pokemon tile represented by Z
        }
        
        samePos = false;
    }
    
    for(i = 0; i < 20; i++)
    {
        wildPokemons.push_back(allPokemons[idxs[i]]);
    }
    
    int z;
    
    for(i = 0; i < allPokemons.size(); i++) // erases all the pokemons from allPokemons vector that got pushed back into the wildPokemons vector
    {
        for(z = 0; z < wildPokemons.size(); z++)
        {
            if(wildPokemons[z].getName() == allPokemons[i].getName())
            {
                allPokemons.erase(allPokemons.begin() + i);
            }
        }
    }
    
}

void Main::generateTrainers()
{
    int counter = 0;
    int i;
    int j;
    int z;
    vector<int> tempIdxs;
    bool sameIdx = false;
    
    while(tempIdxs.size() < 90)
    {
        int randIdx = rand() % allPokemons.size();
        
        if(tempIdxs.size() > 0 )
        {
            for(i = 0; i < tempIdxs.size(); i++)
            {
                if(randIdx == tempIdxs[i])
                {
                    sameIdx = true;
                    break;
                }
            }
        }
        
        if(sameIdx == false)
        {
            tempIdxs.push_back(randIdx);
        }
        
        sameIdx = false;
    }
    
    while(counter < 15)
    {
        Trainer tempTrainer;
        int numPokes = rand() % 6 + 1;
        string trainerName = "Trainer" + counter;
        
        tempTrainer.setIdx(counter);
        tempTrainer.setNumPokemons(numPokes);
        tempTrainer.setTrainerName(trainerName);
        
        for(i = 0; i < numPokes; i++)
        {
            string tempName = allPokemons[tempIdxs[i]].getName();
            tempTrainer.setTrainerPokemons(tempName);
            tempIdxs.erase(tempIdxs.begin() + i);
        }
        
        // for(i = 0; i < allPokemons.size(); i++)
        // {
        //     for(z = 0; z <numPokes; z++)
        //     {
        //         if(tempTrainer.getPokeName(z) == allPokemons[i].getName())
        //         {
        //             allPokemons.erase(allPokemons.begin() + i);
        //         }
        //     }
        // }
        
        trainers.push_back(tempTrainer);
        
        counter++;
    }
    
    vector<string> pokemonNames;
    
    for(i = 0; i < trainers.size(); i++)
    {
        for(j = 0; j < trainers[i].getNumPokemons(); j++)
        {
            pokemonNames.push_back(trainers[i].getPokeName(j));
        }
    }
    
    int x = 0; 
    
    while(x < pokemonNames.size())
    {
        for(i = 0; i < allPokemons.size(); i++)
        {
            if(pokemonNames[x] == allPokemons[i].getName())
            {
                allPokemons.erase(allPokemons.begin() + i);
            }
        }
        
        x++;
    }
    
}