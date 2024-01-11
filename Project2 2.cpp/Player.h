#ifndef PLAYER_H
#define PLAYER_H


#include<iostream>
using namespace std;

struct Candy
{
    string name;
    string description;
    string effect_type;
    double effect_value;
    string candy_type;
    double price;
   // Candy(string name,  string description, string effect_type, double effect_value, string candy_type, double price);
};


struct Deck
{
    string name;
    int amount;
  

};

struct Character
{
    string name;
    int stamina;
    int gold;
    vector<string>candies;
};



class Player
{
public:
Player();
Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE);

void printPlayer();
void setStamina(int);
void setGold(double);
void setEffect(string);
void setName(string); 
void setCharacterName(string);
void setSkip(int);    
void setPlayerPosition(int position);

int getSkip() const; 
int getPlayerPosition() const;
int getCandyAmount() const;
int getStamina() const;
double getGold() const;
string getEffect() const;
string getName() const;
string getCharacterName() const;
bool removeCandy(string candy_name);
bool addCandy(Candy candy);
void printInventory();
Player characterSelect(Player Option, string noRepeats);
Candy findCandy(string candy_name);	
vector<Candy> initialize();
Player Calamity(Player option);
Player useCandy(Player&,Player&); // hard function
Player special(Player&);
Player hiddenTreasure(Player&);
Player sameTile(Player , int,Player);
vector<Candy> readcandy(Player);



private:
const static int _MAX_CANDY_AMOUNT = 9;
int _stamina;
double _gold;
string _effect;
int _candy_amount;
string _name;
string _characterName;
char _symbol;
int _player_position;
int _skip;

Candy _inventory[_MAX_CANDY_AMOUNT];


};
#endif