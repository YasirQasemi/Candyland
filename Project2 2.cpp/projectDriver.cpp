#include "board.h"
#include "Player.h"
#include "CandyStore.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <cstdlib> // random
#include <ctime>   // time()

using namespace std;

void playerStats(Player option);
Player sameTile(Player option, int temp);
int main()
{
    Board board1;

    board1.initializeTiles();
    //board1.practice();
    //board1.readtiletype();// this is test

    string noRepeats;
    int participants;
    Player PlayerOne;
    Player PlayerTwo;
    int p1temp = 0;
    int p2temp = 0;
    // int counter = 0;
    PlayerOne.setPlayerPosition(0);
    PlayerTwo.setPlayerPosition(0);
    CandyStore store;

    char option1;
    char option2;
    cout << "Welcome to the game of Candyland. Please enter the number of participants(2 MAX)(Everything in Case Sensitive in this game): " << endl;
    cin >> participants;

    PlayerOne = PlayerOne.characterSelect(PlayerOne, noRepeats);
    cout << "Do you want to visit the Candy Store(y/n)" << endl;
    cin >> option1;
    if (option1 == 'y')
    {
        PlayerOne = store.displaycandy(PlayerOne);
        cout << "This is your inventory now" << endl;
        playerStats(PlayerOne);
    }

    // store.displaycandy();
    noRepeats = PlayerOne.getCharacterName();
    PlayerTwo = PlayerTwo.characterSelect(PlayerTwo, noRepeats);
    cout << "Do you want to visit the Candy Store(y/n)" << endl;
    cin >> option2;
    if (option2 == 'y')
    {
        PlayerTwo = store.displaycandy(PlayerTwo);
        cout << "This is your inventory now" << endl;
        playerStats(PlayerTwo);
    }
    cout << "Time to Play" << endl;

    // Game loop
    board1.displayBoard(PlayerOne, PlayerTwo);

    bool win = false;

    char option;
    while (!win)
    {
        //  to keep track of same, use a counter or temp variable

        // need to implement a 0 stamina skip turn
        int playeroneoption = 0;
        int playertwooption = 0;
        cin.clear();
        cin.ignore();
        if (PlayerOne.getSkip() == 0 && PlayerOne.getStamina() != 0)
        {
            while (playeroneoption != 1)
            {
                cout << "It's " << PlayerOne.getName() << "'s turn" << endl;
                cout << "Please select a menu option" << endl;
                cout << "1. Draw a card\n2. Use candy\n3. Show player stats" << endl;
                cin >> playeroneoption;
                if (playeroneoption == 1)
                {
                    cout << "Press D" << endl;
                    cin >> option;
                    while ((option != 'D' && option != 'd'))
                    {
                        cout << "Invalid Selection. Press D" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cin >> option;
                    }

                    PlayerOne = board1.randomCard(PlayerOne);
                    PlayerOne.setStamina(PlayerOne.getStamina() - 1);
                    p1temp = PlayerOne.getPlayerPosition();
                    PlayerOne = PlayerOne.sameTile(PlayerOne, p2temp, PlayerTwo);
                    // player function
                    string tiletype;
                    tiletype = board1.getType(PlayerOne);

                    if (tiletype == "Special Tiles")
                    {
                        PlayerOne.special(PlayerOne);
                    }
                    if (tiletype == "Hidden Tile")
                    {
                        PlayerOne.hiddenTreasure(PlayerOne);
                    }
                    if (tiletype == "CandyStore")
                    {
                        char pp = 0;
                        cout << "You landed on a candy store. Do you want to buy a candy?(y/n)" << endl;
                        cin>>pp;
                        if (pp == 'y')
                        {
                            PlayerOne = store.displaycandy(PlayerOne);
                        }
                    }
                    if (tiletype == "Regular Tile")
                    {
                        PlayerOne = PlayerOne.Calamity(PlayerOne);
                    }
                    if(tiletype =="Gummy Candy")
                    {
                        cout<<"You landed on a Gummy Candy tile. You will be skipped 2 times."<<endl;
                        PlayerOne.setSkip(2);
                    }

                    board1.displayBoard(PlayerOne, PlayerTwo);
                }
                else if (playeroneoption == 2)
                {
                    PlayerOne.useCandy(PlayerOne, PlayerTwo);
                }
                else if (playeroneoption == 3)
                {
                    playerStats(PlayerOne);
                }
                if (PlayerOne.getPlayerPosition() >= board1.getBoardSize() - 1)
                { // if it doesnt work, do board1.getBoardSize() -1
                    cout << PlayerOne.getName() << " wins!" << endl;
                    win = true;
                    break;
                }

                char c;
                cout << "Press c to continue" << endl;
                cin >> c;
                while (!(c == 'c' || c == 'C'))
                {
                    cout << "Invalid selection. \nPlease press c." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cin >> c;
                }
            }
        }
        else
        {
            if (PlayerOne.getStamina() == 0)
            {
                cout << "You ran out of stamina. You will be given 1 stamina next round." << endl;
                PlayerOne.setStamina(1);
            }
            cout << PlayerOne.getName() << " is skipped" << endl;
            if (PlayerOne.getSkip() != 0)
            {
                int skips1 = PlayerOne.getSkip() - 1;
                PlayerOne.setSkip(skips1);
            }
        }

        // player 2

        if (PlayerTwo.getSkip() == 0 && PlayerTwo.getStamina() != 0)
        {
            while (playertwooption != 1)
            {
                cout << "It's " << PlayerTwo.getName() << "'s turn" << endl;
                cout << "Please select a menu option" << endl;
                cout << "1. Draw a card\n2. Use candy\n3. Show player stats" << endl;
                cin >> playertwooption;
                if (playertwooption == 1)
                {
                    cout << "Press D" << endl;
                    cin >> option;
                    while ((option != 'D' && option != 'd'))
                    {
                        cout << "Invalid Selection. Press D" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cin >> option;
                    }
                    PlayerTwo = board1.randomCard(PlayerTwo);
                    PlayerTwo.setStamina(PlayerTwo.getStamina() - 1);
                    p2temp = PlayerTwo.getPlayerPosition();
                    PlayerTwo = PlayerTwo.sameTile(PlayerTwo, p1temp, PlayerOne);
                    // player function
                    string tiletype1;
                    tiletype1 = board1.getType(PlayerTwo);
                    if (tiletype1 == "Special Tiles")
                    {
                         PlayerTwo.special(PlayerTwo);
                    }
                    if (tiletype1 == "Hidden Tile")
                    {
                        PlayerTwo.hiddenTreasure(PlayerTwo);
                    }
                    if (tiletype1 == "CandyStore")
                    {
                        char ppp = 0;
                        cout << "You landed on a candy store. Do you want to buy a candy?(y/n)" << endl;
                        cin>>ppp;
                        if (ppp == 'y')
                        {
                            PlayerTwo = store.displaycandy(PlayerTwo);
                        }
                    }
                    if (tiletype1 == "Regular Tile")
                    {
                        PlayerTwo = PlayerTwo.Calamity(PlayerTwo);
                    }
                    if(tiletype1 =="Gummy Candy")
                    {
                        cout<<"You landed on a Gummy Candy tile. You will be skipped 2 times."<<endl;
                        PlayerTwo.setSkip(2);
                    }

                    board1.displayBoard(PlayerOne, PlayerTwo);
                }
                else if (playertwooption == 2)
                {
                    PlayerOne.useCandy(PlayerTwo, PlayerOne);
                }
                else if (playertwooption == 3)
                {
                    playerStats(PlayerTwo);
                }
                if (PlayerTwo.getPlayerPosition() >= board1.getBoardSize() - 1)
                {
                    cout << PlayerTwo.getName() << " wins!" << endl;
                    win = true;
                    break;
                }
                char d;
                cout << "Press c to continue" << endl;
                cin >> d;
                while (!(d == 'c' || d == 'C'))
                {
                    cout << "Invalid selection. \nPlease press c." << endl;
                    cin.clear();
                    cin.ignore();

                    cin >> d;
                }

                // PlayerTwo.printInventory();
                // board1.displayBoard(PlayerOne, PlayerTwo);
            }
        }
        else
        {
            if (PlayerTwo.getStamina() == 0)
            {
                cout << "You ran out of stamina. You will be given 1 stamina next round." << endl;
                PlayerTwo.setStamina(3);
            }
            cout << PlayerTwo.getName() << " is skipped" << endl;
            if (PlayerTwo.getSkip() != 0)
            {
                int skips = PlayerTwo.getSkip() - 1;
                PlayerTwo.setSkip(skips);
            }
        }
    }
    vector<Candy>vec1 = PlayerOne.readcandy(PlayerOne);
    vector<Candy>vec2 = PlayerTwo.readcandy(PlayerTwo);
    
    ofstream outputFile("game_stats.txt");
    outputFile << "Player One Stats:" << endl;
    outputFile << "Name: " << PlayerOne.getName() << endl;
    outputFile << "Stamina: " << PlayerOne.getStamina() << endl;
    outputFile << "Gold: " << PlayerOne.getGold() << endl;
    outputFile <<"Candies: "<<endl;
    for(int i=0; i<9;i++)
    {
        outputFile << vec1[i].name<<endl;
    }

    outputFile << "Player Two Stats:" << endl;
    outputFile << "Name: " << PlayerTwo.getName() << endl;
    outputFile << "Stamina: " << PlayerTwo.getStamina() << endl;
    outputFile << "Gold: " << PlayerTwo.getGold() << endl;
    outputFile <<"Candies: "<<endl;
    for(int i=0; i<9;i++)
    {
        outputFile << vec2[i].name<<endl;
    }
    

    outputFile.close();
    return 0;
}

void playerStats(Player option)
{
    cout << "Player Name: " << option.getName() << endl;
    cout << "Character: " << option.getCharacterName() << endl;
    cout<<"Gold: "<<option.getGold()<<endl;
    cout << "Stamina: " << option.getStamina() << endl;
    
    option.printInventory();
}



