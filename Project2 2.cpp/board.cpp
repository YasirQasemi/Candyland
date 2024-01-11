#include "board.h"
#include "Player.h"

#include <cstdlib> // random
#include <ctime>   // time()
Board::Board()
{
    resetBoard();
}

void Board::resetBoard()
{
    // have to fix this
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile new_tile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        new_tile = {current_color, "Regular tile"};
        _tiles[i] = new_tile;
    }
    new_tile = {ORANGE, "Regular tile"};
    _tiles[_BOARD_SIZE - 1] = new_tile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    _player_position = 0;
}

void Board::displayTile(int position, Player option1, Player option2)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";
    // if(option1.getPlayerPosition() == option2.getPlayerPosition())
    // {
    //     cout<<"Start";
    // }
    if (option1.getPlayerPosition() == 0 && option2.getPlayerPosition() == 0 && position == 0)
    {

        cout << "ST";
    }
    else
    {
        if (position == option1.getPlayerPosition())
        {
            cout << "P1";
        }
        else if (position == option2.getPlayerPosition())
        {
            cout << "P2";
        }
        else
        {
            cout << "  ";
        }
    }
    cout << " " << RESET;
}

void Board::displayBoard(Player option1, Player option2)
{

    for (int i = 0; i <= 23; i++)
    {
        displayTile(i, option1, option2);
    }
    cout << endl;
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "    ";
        }

        displayTile(i, option1, option2);

        cout << endl;
    }
    for (int i = 52; i > 28; i--)
    {
        displayTile(i, option1, option2);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i, option1, option2);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i, option1, option2);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int new_position)
{
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position = new_position;
        return true;
    }
    return false;
}

int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition() const
{
    return _player_position;
}

bool Board::addCandyStore(int position)
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _candy_store_position[_candy_store_count] = position;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if (_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    return false;
}

Player Board::movePlayer(Player option, int tile_to_move_forward)
{
    Player updatedPlayer = option;
    int new_player_position = tile_to_move_forward + option.getPlayerPosition();
    if (new_player_position >= 0 && new_player_position < _BOARD_SIZE)
    {
        updatedPlayer.setPlayerPosition(new_player_position);
    }

    
    
    return updatedPlayer;
}

Player Board::randomCard(Player player)
{
   
    Deck temp;
    Board board1;
    vector<Deck> cards =
        {
            {"blue card", 3},
            {"magenta card", 3},
            {"green card", 3},
            {"blue card", 3},
            {"magenta card", 3},
            {"green card", 3},
            {"double green card", 6},
            {"double blue card", 6},
            {"double magenta card", 6}};

    srand(time(0));
    for (int i = cards.size() - 1; i > 0; --i)
    {
        int j = rand() % (i + 1);

        if (i != j)
        {
            temp = cards[i];
            cards[i] = cards[j];
            cards[j] = temp;
        }
    }

    int x = cards[0].amount;
    int position = player.getPlayerPosition();
    int newposition;

    if (x == 6)
    {
        if (cards[0].name == "double blue card")
        {
            cout << "You drew a double blue card. Your game piece advances to the next 2 blue tiles." << endl;
            for (int p = 4; p <= 6; p++)
            {
                if ((position + p) % 3 == 2)
                {
                    newposition = p;
                }
            }
        }
        if (cards[0].name == "double magenta card")
        {
            cout << "You drew a double magenta card. Your game piece advances to the next 2 magenta tiles." << endl;
            for (int p = 4; p <= 6; p++)
            {
                if ((position + p) % 3 == 0)
                {
                    newposition = p;
                }
            }
        }
        if (cards[0].name == "double green card")
        {
            cout << "You drew a double green card. Your game piece advances to the next 2 green tiles." << endl;
            for (int p = 4; p <= 6; p++)
            {
                if ((position + p) % 3 == 1)
                {
                    newposition = p;
                }
            }
        }
    }
    if (x == 3)
    {
        if (cards[0].name == "blue card")
        {
            cout << "You drew a single " << cards[0].name << ". Your game piece advances to the next blue tile." << endl;
            for (int p = 1; p <= 3; p++)
            {
                if ((position + p) % 3 == 2)
                {
                    newposition = p;
                }
            }
        }
        if (cards[0].name == "magenta card")
        {
            cout << "You drew a single " << cards[0].name << ". Your game piece advances to the next magenta tile." << endl;
            for (int p = 1; p <= 3; p++)
            {
                if ((position + p) % 3 == 0)
                {
                    newposition = p;
                }
            }
        }
        if (cards[0].name == "green card")
        {
            cout << "You drew a single " << cards[0].name << ". Your game piece advances to the next green tile." << endl;
            for (int p = 1; p <= 3; p++)
            {
                if ((position + p) % 3 == 1)
                {
                    newposition = p;
                }
            }
        }
    }

    return movePlayer(player, newposition);
}

void Board::sameTile(Player option1, Player option2)
{
    // in this function, it will take both players position, if
    // they on the same tile, then the one that was there last will move back one
}

void Board::initializeTiles()
{
    srand(time(0));
    for (int i = 0; i < _BOARD_SIZE; i+=10)
    {
        _tiles[i].tile_type = "Special Tile";
    }
    int treasureTile = 0;
    for (int i = 0; i < 15; i++)
    {
        treasureTile = rand() % 82;
        if(_tiles[treasureTile].tile_type == "Special Tile" ||_tiles[treasureTile].tile_type == "CandyStore One" ||_tiles[treasureTile].tile_type == "CandyStore Two" ||_tiles[treasureTile].tile_type == "CandyStore Three")
        {
            treasureTile++;
        }
        _tiles[treasureTile].tile_type = "Hidden Tile";
    }
    int candystore1 = 0;
    int candystore2 = 0;
    int candystore3 = 0;
    candystore1 = rand() % 27;
    candystore2 = rand() % 27 + 28;
    candystore3 = rand() % 27 + 55;
    
    for (int p = 1; p <= 3; p++)
    {
        if ((candystore1) % 3 == 0)
        {
            if(_tiles[candystore1].tile_type == "Special Tile" ||_tiles[candystore1].tile_type == "Hidden Tile" ||_tiles[candystore1].tile_type == "CandyStore Two" ||_tiles[candystore1].tile_type == "CandyStore Three")
        {
            candystore1+=3;
            if(candystore1 >27)
            {
                candystore1 =15;
            }
        }
            _tiles[candystore1].tile_type = "CandyStore One";
        }
        candystore1++;
    }
    for (int p = 1; p <= 3; p++)
    {
        if ((candystore2) % 3 == 1)
        {
            if(_tiles[candystore2].tile_type == "Special Tile" ||_tiles[candystore2].tile_type == "Hidden Tile" ||_tiles[candystore2].tile_type == "CandyStore One" ||_tiles[candystore2].tile_type == "CandyStore Three")
        {
            candystore2+=3;
            if(candystore2 >54)
            {
                candystore2 =34;
            }
        }
            _tiles[candystore2].tile_type = "CandyStore Two";
        }
        candystore2++;
    }
    for (int p = 1; p <= 3; p++)
    {
        if ((candystore3) % 3 == 2)
        {
            if(_tiles[candystore3].tile_type == "Special Tile" ||_tiles[candystore3].tile_type == "Hidden Tile" ||_tiles[candystore3].tile_type == "CandyStore Two" ||_tiles[candystore3].tile_type == "CandyStore One")
        {
            candystore3+=3;
            if(candystore3 >82)
            {
                candystore3 =62;
            }
        }
            _tiles[candystore3].tile_type = "CandyStore Three";
        }
        candystore3++;
    }
    
}
void Board::practice()
 {
    for(int i =0; i<82; i++)
    {
        _tiles[i].tile_type = "Special Tile";
    }
 }
string Board::getType(Player option)
{
    Board board1;
    board1.practice();
    if (_tiles[option.getPlayerPosition()].tile_type =="Special Tile")
    {
        return "Special Tiles";
    }
    if (_tiles[option.getPlayerPosition()].tile_type =="Hidden Tile")
    {
        return "Hidden Tile";
    }
    if (_tiles[option.getPlayerPosition()].tile_type =="CandyStore One")
    {
        return "CandyStore";
    }
    if (_tiles[option.getPlayerPosition()].tile_type =="CandyStore Two")
    {
        return "CandyStore";
    }
    if (_tiles[option.getPlayerPosition()].tile_type =="CandyStore Three")
    {
        return "CandyStore";
    }
    if (_tiles[option.getPlayerPosition()].tile_type =="Gummy Candy")
    {
        return "Gummy Candy";
    }
    return "Regular Tile";
}

void Board::readtiletype()
{
    for(int i =0; i<83; i++)
    {
        cout<<_tiles[i].tile_type<<i<<endl;
    }
}


int Board::playerontile(int tile, Player op2)
 {
    
    int p2 = op2.getPlayerPosition();
    if(tile == p2)
    {
        return 1;
    }
    else{
        return 2;
    }
 }
void Board::gummyTiles(int tile)
{
    _tiles[tile].tile_type ="Gummy Candy";

}

 