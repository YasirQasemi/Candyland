#ifndef CANDYSTORE_H
#define CANDYSTORE_H
#include "board.h"
#include "Player.h" 
#include<iostream>
using namespace std;

class CandyStore {
public:
    CandyStore();
    CandyStore(string store_name);
    Player addCandy(Candy candy);
    Player displaycandy(Player);

private:
    static const int MAX_CANDY = 11;
    string store_name;
    int candy_count;
    Candy candies[MAX_CANDY];
};

#endif


