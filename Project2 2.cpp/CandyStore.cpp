
#include "CandyStore.h"
#include "board.h"

CandyStore::CandyStore()
{
  store_name = "";
  candy_count = 0;
}
CandyStore::CandyStore(string _store_name)
{
  store_name = _store_name;
  candy_count = 0;
}
Player CandyStore::addCandy(Candy candy)
{
  Player option;
  if (candy_count == MAX_CANDY)
  {
    cout << "Player has max candies. Unable to add more" << endl;

    return option;
  }
  candies[candy_count] = candy;
  candy_count++;
  return option;
  // i will also be adding a substitution method in here
}
Player CandyStore::displaycandy(Player example)
{

  srand(time(0));
  vector<Candy> temp;
  Candy tempcandy;
  vector<Candy> store;
  temp = example.initialize();
  int d = rand() % 11;
  while (temp[d].candy_type != "magical")
  {
    d = rand() % 11;
  }
  store.push_back(temp[d]);
  while (temp[d].candy_type != "poison")
  {
    d = rand() % 11;
  }
  store.push_back(temp[d]);
  while (temp[d].candy_type != "gummy")
  {
    d = rand() % 11;
  }
  store.push_back(temp[d]);
  while (temp[d].candy_type != "immunity")
  {
    d = rand() % 11;
  }
  store.push_back(temp[d]);
  for (int i = 4 - 1; i > 0; --i)
  {
    int j = rand() % (i + 1);

    if (i != j)
    {
      tempcandy = store[i];
      store[i] = store[j];
      store[j] = tempcandy;
    }
  }
  // i read the file in the player, i just need to implement it here
  cout << "Candies to buy: " << endl;
  for (int i = 0; i < 3; i++)
  {
    cout << "Here is a list of candies in the candy store: " << endl;
    cout << "Name: " << store[i].name << endl;
    cout << "Description: " << store[i].description << endl;
    cout << "Effect: " << store[i].effect_type << endl;
    cout << "Effect value: " << store[i].effect_value << endl;
    cout << "Candy type: " << store[i].candy_type << endl;
    cout << "Price " << store[i].price << endl;

    cout << "--------------------------------------------------" << endl;
  }
  string playeroption;
  // Candy playerop;
  int count= 0;
  cout << "Which candy would you like to buy?" << endl;
  cin.ignore();
  getline(cin, playeroption);
  bool validChoice = false;
  bool invalidChoice = false;
  while (!validChoice)
  {
    for (int i = 0; i < 3; i++)
    {
      if (store[i].name == playeroption)
      {

        while (example.getGold() < store[i].price && invalidChoice == false)
        {
          string newchoice;
          cout << "You do not have enough gold for this" << endl;
          cout << "Please choose another candy or enter a different option: " << endl;
         
          getline(cin, newchoice);
          for(int j=0; j<3; j++)
          {
            
            if(store[j].name == newchoice)
            {
              
              invalidChoice = true;

              continue;
            }
            count++;
          }
        }
        validChoice = false;
        if (example.getCandyAmount() == 9)
        {
          char substituteChoice;
          cout << "You do not have sufficient space in the candy inventory. \n Would you like to substitute your candy with any existing candy? (y/n)" << endl;

          cin >> substituteChoice;

          if (substituteChoice == 'y')
          {
            string substitute;
            cout << "Which candy would you like to substitute?" << endl;
            cin >> substitute;
            example.removeCandy(substitute);
            example.addCandy(store[i]);
          }
          else
          {
            cout << "You chose not to substitute. Your candy inventory is unchanged." << endl;
          }
        }
        else
        {
          if(invalidChoice == false)
          {
          example.addCandy(store[i]);
          int newgold = example.getGold() - store[i].price;
          if(newgold<0)
          {
            newgold = 0;
          }
          example.setGold(newgold);
          }
          else{
            example.addCandy(store[count]);
          int newgold = example.getGold() - store[count].price;
          if(newgold<0)
          {
            newgold = 0;
          }
          example.setGold(newgold);
          }
        }
        validChoice = true;
        break; // Exit the loop once the candy is found
      }
    }
  }
    return example;
  }