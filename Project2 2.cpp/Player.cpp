#include <iostream>
#include <cctype>
#include "Player.h"
#include "board.h"
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

void Player::setStamina(int stamina)
{
    _stamina = stamina;
}

void Player::setGold(double gold)
{
    _gold = gold;
}
void Player::setEffect(string effect)
{
    _effect = effect;
}
void Player::setName(string name)
{
    _name = name;
}

void Player::setCharacterName(string characterName)
{
    _characterName = characterName;
}

void Player::setPlayerPosition(int position)
{
    _player_position = position;
}

void Player::setSkip(int skip)
{
    _skip = skip;
}

int Player::getSkip() const
{
    return _skip;
}
int Player::getPlayerPosition() const
{
    return _player_position;
}

int Player::getCandyAmount() const
{

    return _candy_amount;
}

int Player::getStamina() const
{
    return _stamina;
}
double Player::getGold() const
{
    return _gold;
}
string Player::getEffect() const
{
    return _effect;
}
string Player::getName() const
{
    return _name;
}
string Player::getCharacterName() const
{
    return _characterName;
}

Player::Player()
{
    _stamina = 0;
    _gold = 0;
    _effect = "";
    _candy_amount = 0;
    _skip = 0;
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        _inventory[i].name = "";
        _inventory[i].description = "";
        _inventory[i].price = 0;
        _inventory[i].candy_type = "";
    }
}
Player::Player(int stamina, double gold, string effect, Candy candy_array[], const int CANDY_ARR_SIZE)
{
    _stamina = stamina;
    _gold = gold;
    _effect = effect;
    _candy_amount = 0;
    // struct needs to be set to zero
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        _inventory[i].name = "";
        _inventory[i].description = "";
        _inventory[i].price = 0;
        _inventory[i].candy_type = "";
    }
    for (int i = 0; i < CANDY_ARR_SIZE && i < _MAX_CANDY_AMOUNT; i++)
    {

        if (candy_array[i].name != "")
        {
            _inventory[_candy_amount] = candy_array[i];
            _candy_amount++;
        }
    }
}

string finalstring(string candy_name)
{
    
    for (int i = 0; i < candy_name.length(); ++i)
    {
        if (i == 0 || candy_name[i - 1] == ' ')
        {
            candy_name[i] = toupper(candy_name[i]);
        }
        else
        {
            candy_name[i] = tolower(candy_name[i]);
        }
    }

    return candy_name;
}

void Player::printInventory()
{
    for (int i = 0; i < _candy_amount; i++)
    {
        _inventory[i].name = finalstring(_inventory[i].name);
    }
    if (_candy_amount == 9)
    {

        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[" << _inventory[4].name << "]|[" << _inventory[5].name << "]|" << endl;
        cout << "|[" << _inventory[6].name << "]|[" << _inventory[7].name << "]|[" << _inventory[8].name << "]|" << endl;
    }
    if (_candy_amount == 8)
    {

        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[" << _inventory[4].name << "]|[" << _inventory[5].name << "]|" << endl;
        cout << "|[" << _inventory[6].name << "]|[" << _inventory[7].name << "]|[Empty]|" << endl;
    }
    if (_candy_amount == 7)
    {

        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[" << _inventory[4].name << "]|[" << _inventory[5].name << "]|" << endl;
        cout << "|[" << _inventory[6].name << "]|[Empty]|[Empty]|" << endl;
    }
    if (_candy_amount == 6)
    {

        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[" << _inventory[4].name << "]|[" << _inventory[5].name << "]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else if (_candy_amount == 5)
    {
        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[" << _inventory[4].name << "]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else if (_candy_amount == 4)
    {

        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[" << _inventory[2].name << "]|" << endl;
        cout << "|[" << _inventory[3].name << "]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else if (_candy_amount == 3)
    {
        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|" << _inventory[2].name << "]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else if (_candy_amount == 2)
    {
        cout << "|[" << _inventory[0].name << "]|[" << _inventory[1].name << "]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else if (_candy_amount == 1)
    {
        cout << "|[" << _inventory[0].name << "]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
    else
    {
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
        cout << "|[Empty]|[Empty]|[Empty]|" << endl;
    }
}

Candy Player::findCandy(string candy_name)
{
    Candy cand;
    for (int i = 0; i < candy_name.length(); i++)
    {
        char c = candy_name[i];
        candy_name[i] = tolower(c);
    }

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
        {

            for (int j = 0; j < _inventory[i].name.length(); j++)
            {
                char c = _inventory[i].name[j];
                _inventory[i].name[j] = tolower(c);
            }
        }
        for (int i = 0; i < _candy_amount; i++)
        {
            if (_inventory[i].name == candy_name)
            {
                return _inventory[i];
            }
        }
    }
    return cand;
}
bool Player::addCandy(Candy candy)
{
    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if (_inventory[i].name == "") // && other options
        {
            _inventory[i] = candy;
            _candy_amount++;
            return true;
        }
    }
    return false;
}
bool Player::removeCandy(string candy_name)
{

    for (int i = 0; i < candy_name.length(); i++)
    {
        char c = candy_name[i];
        candy_name[i] = tolower(c);
    }

    for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        for (int i = 0; i < _MAX_CANDY_AMOUNT; i++)
        {

            for (int j = 0; j < _inventory[i].name.length(); j++)
            {
                char c = _inventory[i].name[j];
                _inventory[i].name[j] = tolower(c);
            }
        }
        if (_inventory[i].name == candy_name) // && other options
        {
            for (int b = i; b < 3; b++)
            {
                _inventory[b] = _inventory[b + 1];
            }
            _inventory[_MAX_CANDY_AMOUNT - 1].name = "";
            _inventory[_MAX_CANDY_AMOUNT - 1].description = "";
            _inventory[_MAX_CANDY_AMOUNT - 1].price = 0;
            _inventory[_MAX_CANDY_AMOUNT - 1].candy_type = "";

            _candy_amount--;
            //_candy_amount = _candy_amount -1;
            return true;
        }
    }

    return false;
}
Player Player::characterSelect(Player Option, string noRepeats)
{

    string choice;
    // File variables
    string _name;
    string _stamina;
    string _gold;
    string _candies;
    Character input;
    vector<Character> characterMenu;
    string line;
    ifstream fin2;
    ifstream fin;
    fin.open("character.txt");

    string charname;

    cout << "Enter player name:" << endl;
    cin >> charname;
    Option.setName(charname);

    cout << "Awesome! Here is a list of characters a player can select from: " << endl;

    while (getline(fin, line))
    {

        input.candies.clear();
        stringstream ss(line);
        getline(ss, _name, '|');
        getline(ss, _stamina, '|');
        getline(ss, _gold, '|');
        getline(ss, _candies);
        if (_name.empty())
        {
            continue;
        }

        input.name = _name;
        input.stamina = stoi(_stamina);
        input.gold = stoi(_gold);
        stringstream candiesStream(_candies);
        while (getline(candiesStream, _candies, ','))
        {
            input.candies.push_back(_candies);
        }
        characterMenu.push_back(input);
        if (noRepeats == input.name)
        {
            continue;
        }

        cout << "Name: " << input.name << "\nStamina: " << input.stamina << "\nGold: " << input.gold << "\nCandies: \n";

        for (int i = 0; i < input.candies.size(); i += 3)
        {
            for (int j = 0; j < 3 && (j + i < input.candies.size()); j++)
            {
                cout << "[" << input.candies.at(j + i) << "] ";
            }

            cout << "\n";
        }
        cout << "--------------------------------------------" << endl;
    }

    cout << "The selection character is" << endl;
    cin.ignore();
    getline(cin, choice);

    for (int i = 0; i < characterMenu.size(); i++)
    {

        if (choice == characterMenu[i].name)
        {

            Option.setCharacterName(characterMenu[i].name);
            Option.setStamina(characterMenu[i].stamina);
            Option.setGold(characterMenu[i].gold);

            for (int j = 0; j < characterMenu[i].candies.size(); j++)
            {

                Candy candy;
                candy.name = characterMenu[i].candies[j];
                Option.addCandy(candy);
            }
            // Option.printInventory();
            // cout << "Player Name: " << Option.getCharacterName() << endl;
            // cout << "Stamina: " << Option.getStamina() << endl;
            // cout << "Gold: " << Option.getGold() << endl;
            break;

            // Player.candies.push_back(input.candies[i]);
        }
    }
    return Option;
}

vector<Candy> Player::initialize()
{
    vector<Candy> candies;
    ifstream fin;
    string line;
    fin.open("candyfile.txt");
    string _name;
    string _description;
    string _effect_type;
    string _effect_value;
    string _candy_type;
    string _price;
    Candy candy;

    while (getline(fin, line))
    {
        stringstream ss(line);
        getline(ss, _name, '|');
        getline(ss, _description, '|');
        getline(ss, _effect_type, '|');
        getline(ss, _effect_value, '|');
        getline(ss, _candy_type, '|');
        getline(ss, _price);
        candy.name = _name;
        candy.description = _description;
        candy.effect_type = _effect_type;
        candy.effect_value = stoi(_effect_value);
        candy.candy_type = _candy_type;
        candy.price = stoi(_price);

        candies.push_back(candy);
    }
    return candies;
}

Player Player::Calamity(Player option)
{

    int calamity;
    Board board1;
    int choice;
    srand(time(0));
    calamity = rand() % 100 + 1; // Generate random number 1 to 100
    bool c = false;
    if (c)
    {
        return option;
    }
    
        if (calamity <= 40) // 40% chance
        {
            choice = rand() % 100;
            if (choice <= 15) // 15 perecnet
            {
                // Candy Avalanche!
                // rock paper sisscors
                bool win = false;
                cout << "Watch out! A candy avalanche has struck! You can play rock paper scissors to negate the avalanche." << endl;
                while (win == false)
                {
                    char computerchoice;
                    int computernum = rand() % 3 + 1;

                    if (computernum == 1)
                    {
                        computerchoice = 'r';
                    }
                    if (computernum == 2)
                    {
                        computerchoice = 'p';
                    }
                    if (computernum == 3)
                    {
                        computerchoice = 's';
                    }
                    char userchoice;
                    cout << "Pick r,p, or s" << endl;
                    cin >> userchoice;
                    while (!(userchoice == 'r' || userchoice == 'p' || userchoice == 's'))
                    {

                        cout << "Invalid selection!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin >> userchoice;
                    }

                    if (userchoice == computerchoice)
                    {
                        cout << "Tie! Play again" << endl;
                    }
                    if ((userchoice == 'r' && computerchoice == 's') || (userchoice == 's' && computerchoice == 'p') || (userchoice == 'p' && computerchoice == 'r'))
                    {
                        // wins
                        cout << "You've won! You negated the avalanche." << endl;

                        return option;
                        win = true;
                        c = true;
                        break;
                    }
                    else if ((computerchoice == 'r' && userchoice == 's') || (computerchoice == 's' && userchoice == 'p') || (computerchoice == 'p' && userchoice == 'r'))
                    {
                        // loses
                        cout << "You've lost! You will lost 10 units of stamina and forced to skip your next round." << endl;
                        option.setSkip(1);
                        int lost = option.getGold() - 10;
                        option.setGold(lost);

                        return option;
                        win = true;
                        c = true;
                        break;
                    }
                }
            }
            else if (choice > 15 && choice <= 35)
            {
                // good calamity
                cout << "Lucky you, The Leprechauns will give you 10 gold!" << endl;
                int gain = 0;
                gain = option.getGold() + 10;
                option.setGold(gain);
            }
            else if (choice > 35 && choice <= 65)
            {
                // candy bandits
                int randomgold = rand() % 9 + 1;
                int lost = 0;

                
                lost = option.getGold() - randomgold;
                if(lost <0)
                {
                    lost = 0;
                }
                cout << "Oh no! Candy Bandits have swiped your gold coins!" << endl;
                cout << "You have lost " << lost << " gold." << endl;
                option.setGold(lost);
            }
            else if (choice > 65 && choice <= 100)
            {
                // Lost in a Lollipop Labyrinth
                // rock paper sisscors
                bool win = false;
                cout << "Oh dear! You got lost in the lollipop labyrinth!" << endl;
                cout << "Play a rock paper scissors to negate the labyrinth!" << endl;
                while (win == false)
                {
                    char computerchoice;
                    int computernum = rand() % 3 + 1;

                    if (computernum == 1)
                    {
                        computerchoice = 'r';
                    }
                    if (computernum == 2)
                    {
                        computerchoice = 'p';
                    }
                    if (computernum == 3)
                    {
                        computerchoice = 's';
                    }
                    char userchoice;
                    cout << "Pick r,p, or s" << endl;
                    cin >> userchoice;
                    while (!(userchoice == 'r' || userchoice == 'p' || userchoice == 's'))
                    {

                        cout << "Invalid selection!" << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cin >> userchoice;
                    }

                    if (userchoice == computerchoice)
                    {
                        cout << "Tie! Play again" << endl;
                    }
                    if ((userchoice == 'r' && computerchoice == 's') || (userchoice == 's' && computerchoice == 'p') || (userchoice == 'p' && computerchoice == 'r'))
                    {
                        // wins
                        cout << "You won! You negated the attack." << endl;

                        return option;
                        win = true;
                        c = true;
                        break;
                    }
                    else if ((computerchoice == 'r' && userchoice == 's') || (computerchoice == 's' && userchoice == 'p') || (computerchoice == 'p' && userchoice == 'r'))
                    {
                        // loses
                        cout << "You lost. You will be skipped one round" << endl;
                        option.setSkip(1);

                        return option;
                        win = true;
                        c = true;
                        break;
                    }
                }
            }
        }
    
        else
        {
            return option;
        }
    
        return option;
    }
    Player Player::useCandy(Player& option, Player& otherplayer)
    {
        string candy;
        Board board1;
        cout<<"Here's a list of your candies: "<<endl;
        option.printInventory();
        cout<<"Enter a candy you wish to use: "<<endl;
        cin.ignore();
        getline(cin, candy);
        for(int i =0; i<9; i++)
        if(candy == option._inventory[i].name)
        {
            // either candy == frosty or option.inventory
            
            for(int j =0; j<9; j++)
            {
            if(candy == "Frosty Fizz")
            {
                int stam = option.getStamina() +10;
                if(stam >100)
                {
                    stam = 100;
                }
                cout<<"Player's stamina is increased by 10"<<endl;
                option.setStamina(stam);
                option.removeCandy("Frosty Fizz");
                
                return option;
            }
            if(candy =="Lucky Licorice")
            {
                if(otherplayer._inventory[j].name =="Bubblegum Blast")
                {
                    cout<<"Opponent negated the attack"<<endl;
                    otherplayer.removeCandy("Bubblegum Blast");
                    option.removeCandy("Lucky Licorice");
                    return option;
                }
                cout<<"You decreased the opponents stamina by 10"<<endl;
                otherplayer.setStamina(otherplayer.getStamina()-10);
                option.removeCandy("Lucky Licorice");
                return option;
            }
           
            if(candy == "Crimson Crystal")
            {
                int stam1 = option.getStamina() +15;
                if(stam1 >100)
                {
                    stam1 = 100;
                }
                cout<<"Player's stamina is increased by 15"<<endl;
                option.setStamina(stam1);
                option.removeCandy("Crimson Crystal");
                return option;
            }
            
            if(candy == "Venomous Vortex")
            {
                 if(otherplayer._inventory[j].name =="Sparkling Sapphire")
                {
                    cout<<"Opponent negated the attack"<<endl;
                    otherplayer.removeCandy("Sparkling Sapphire");
                    option.removeCandy("Venomous Vortex");
                    return option;
                }
                cout<<"You have decreased the opponents stamina by 15"<<endl;
                otherplayer.setStamina(otherplayer.getStamina()-15);
                option.removeCandy("Venomous Vortex");
                return option;
            }
            if(candy =="Mystic Marshmallow")
            {
                cout<<"Player's stamina is increased by 20"<<endl;
                int stam2 = option.getStamina() +20;
                if(stam2 >100)
                {
                    stam2 = 100;
                }
                option.setStamina(stam2);
                option.removeCandy("Mystic Marshmallow");
                return option;
            }
            if(candy == "Toxic Taffy")
            {
                 if(otherplayer._inventory[j].name =="Caramel Comet")
                {
                    cout<<"Opponent negated the attack"<<endl;
                    otherplayer.removeCandy("Caramel Comet");
                     option.removeCandy("Toxic Taffy");
                    return option;
                }
                cout<<"You have decreased the opponents stamina by 20"<<endl;
                otherplayer.setStamina(otherplayer.getStamina()-20);
                option.removeCandy(candy);
                return option;
            }
            if(candy =="Jellybean of Vigor")
            {
                int add= option.getStamina() +50;
                if(add>100)
                {
                    add = 100;

                }
                option.setStamina(add);
                option.removeCandy("JellyBean of Vigor");

            }
            if(candy =="Ruby Rapture" || candy =="Fearsome Fudge")
            {
                int tile222;
                cout<<"Which Tile do you want a gummy tile on"<<endl;
                cin>>tile222;
                board1.gummyTiles(tile222);
                if(candy =="Ruby Rapture")
                {
                    option.removeCandy("Ruby Rapture");
                    return option;
                }
                option.removeCandy(candy);
                return option;
            }
            }
            

        }
        
        // allows the user to the use the candy they have and will return certain thnigs. This will be a hard function because
        //  i have to include all different types of candy and when they occur, don't know how to start yet
        return option;
    }
    Player Player::special(Player& option)
    {
        Board board;
        
        srand(time(0));
        int type = rand() % 100;
        if (type <= 25)
        {
            // short cut tile
            cout << "You landed on a Short Cut Tile. You move 4 Tiles!" << endl;
            int move;
            move = option.getPlayerPosition() + 4;
            if (move >= 83)
            {
                option.setPlayerPosition(83);
                return option;
            }

            option.setPlayerPosition(move);
            return option;
        }
        if (type > 25 && type <= 50)
        {
            cout << "You landed on a Ice Cream Shop Tile. You get an Extra Turn!" << endl;
            board.randomCard(option);
            // ice cream shop tile
        }
        if (type > 50 && type <= 75)
        {
            int randomgold = rand() % 5 + 5;
            int losegold = option.getGold() - randomgold;
            if(losegold< 0)
            {
                losegold = 0;
            }
            cout << "You landed on a Gumdrop Forest Tile. You move BACK 4 Tiles and lose " << losegold << " gold." << endl;
            int move = 0;
            move = option.getPlayerPosition() - 4;
            if (move <= 0)
            {
                option.setPlayerPosition(0);
                return option;
            }
            option.setPlayerPosition(move);
            return option;

            // gumdrop forest tile
        }
        if (type > 75 && type <= 100)
        {

            cout<<"You landed on a Stamina Tile! Your stamina will be refilled to 100!"<<endl;
            option.setStamina(100);
            return option;
        }
        return option;
    }
    bool riddles()
    {
        ifstream fin;
        string line;
        fin.open("riddle.txt");
        string riddle;
        string answer;
        vector<string> riddlevec;
        vector<string> answervec;
        srand(time(0));
        int riddletype = rand() % 20;
        while (getline(fin, line))
        {
            stringstream ss(line);
            getline(ss, riddle, '|');
            getline(ss, answer);
            riddlevec.push_back(riddle);
            answervec.push_back(answer);
        }
        string playeranswer;
        cout << riddlevec[riddletype] << endl;
        cin >> playeranswer;
        if (playeranswer == answervec[riddletype])
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Player Player::hiddenTreasure(Player& option)
    {
        
        bool yes = riddles();
        bool candy = false;
        
        for(int i =0; i<9; i++)
        {
        if(option._inventory[i].name == "Treasure Hunter's Truffle")
        {
            candy = true;
        }
        }
        if (yes == false)
        {
            cout << "You got the riddle wrong. No treasure for you unless you have a Treasure Hunter's Truffle candy." << endl;
            return option;
        }
        
        if (yes == true||candy == true)
        {
            srand(time(0));
            int type = rand() % 100;
            if (type <= 10)
            {
                // gold winterfall
                int gold = rand() % 20 + 20;
                cout << "Gold Winterfall! You gained " << gold << " gold!" << endl;
                int goldrefill = option.getGold() + gold;
                if (goldrefill >= 100)
                {
                    goldrefill = 100;
                }
                option.setGold(goldrefill);
                return option;
            }
            if (type > 10 && type <= 40)
            {

                int stam = rand() % 20 + 10;
                cout << "You got a stamina refill of " << stam << " units!" << endl;
                int refill = option.getStamina() + stam;
                if (refill >= 100)
                {
                    refill = 100;
                }
                option.setStamina(refill);
                return option;
                // stamina refill
            }
            if (type > 40 && type <= 70)
            {
                Candy Shield;
                Shield.name = "Shield";
                option.addCandy(Shield);
                cout << "You collected the Robber's repel candy." << endl;
                return option;
            }
            if (type > 70 && type <= 100)
            {
                // candy aquistion
                int aqtype = rand() % 100;
                if (aqtype <= 70)
                {
                    Candy jellybean;
                    jellybean.name = "Jellybean of Vigor";
                    option.addCandy(jellybean);
                    cout << "You collected the Jellybean of Vigor candy." << endl;
                    return option;

                    // jellybean
                }
                if (aqtype > 70 && aqtype <= 100)
                {
                    Candy hunter;
                    hunter.name = "Treasure Hunter's Truffle";
                    option.addCandy(hunter);
                    cout << "You collected the Treasure Hunter's Truffle candy." << endl;
                    return option;
                    // hunter truffle
                }
            }
        }
        return option;
    }
    Player Player::sameTile(Player option, int temp,Player option2)
{
    if (option.getPlayerPosition() == temp && option.getPlayerPosition() != 0)
    {
        cout << "You landed on the same tile. You will move back one." << endl;
        option.setPlayerPosition(option.getPlayerPosition() - 1);
         srand(time(0));
    int type = rand() % 25+5;
     int remove = option.getGold() - type;
    if(remove <0)
    {
        remove = 0;
    }
    cout<<"You will lose "<< remove<<" gold."<<endl;
   
    option.setGold(remove);
    option2.setGold(option2.getGold() +remove);
    }
   

    return option;
}

vector<Candy> Player::readcandy(Player option)
{
    vector<Candy> vec;
    for(int i =0; i<9;i++)
    {
        vec.push_back(option._inventory[i]);
    }
    return vec;
}


