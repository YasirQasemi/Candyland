#ifndef BOARD_H
#define BOARD_H
#include "CandyStore.h"
#include "Player.h"

#include <iostream>
#include <vector>
#include<cstdlib> // random
#include<ctime> // time()
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;


struct Tile
{
string color;
string tile_type;
};


class Board
{
private:
    const static int _BOARD_SIZE = 83;
    Tile _tiles[_BOARD_SIZE];
    const static int _MAX_CANDY_STORE = 3;
    int _candy_store_position[_MAX_CANDY_STORE];
    int _candy_store_count;
    int _player_position;
 
    
   
public:
    Board();

    void resetBoard();
    void displayTile(int, Player, Player);
    void displayBoard(Player, Player);
    

    bool setPlayerPosition(int);

    int getBoardSize() const;
    int getCandyStoreCount() const;
    int getPlayerPosition() const;
   
    // Initialize special tiles and candy store tiles
    
    void initializeTiles();
    string getType(Player option);
    void readtiletype();
    int playerontile(int tile, Player);
   


    bool addCandyStore(int);
    bool isPositionCandyStore(int); 
    Player randomCard(Player player);
    Player movePlayer(Player Option, int tile_to_move_forward); // add player
    void sameTile(Player option1, Player option2);
    void practice();
    void gummyTiles(int);
};

#endif