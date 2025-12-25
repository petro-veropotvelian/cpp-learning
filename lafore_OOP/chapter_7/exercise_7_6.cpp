// exercise_7_6.cpp
// In the game of contract bridge, each of four players is dealt 13 cards,
// thus exhausting the entire deck. Modify the CARDARAY program in this
// chapter so that, after shuffling the deck, it deals four hands of 13 cards
// each. Each of the four players' hands should then be displayed.
#include <iostream>
#include <cstdlib>                                                   // for srand(), rand()
#include <ctime>                                                     // for time for srand()
using namespace std;

const int SIZE = 52;
const int HAND_SIZE = 13;
enum Suit { clubs, diamonds, hearts, spades };
// from 2 to 10 are integers without names
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////////////////////////////////
class card
{
private:
   int number;                                                    // 2 to 10, jack, queen, king, ace
   Suit suit;                                                     // clubs, diamonds, hearts, spades
public:
   card()                                                         // constructor
   {
   }
   void set(int n, Suit s)                                        // set card
   {
      suit = s;
      number = n;
   }
   void display();                                                // display card
};
//---------------------------------------------------------------------------------------
void card::display()                                              // display card
{
   if (number >=2 && number <=10)
   {
      cout << number;
   }
   else
   {
      switch (number)
      {
         case jack:
            cout << "J";
            break;
         case queen:
            cout << "Q";
            break;
         case king:
            cout << "K";
            break;
         case ace:
            cout << "A";
            break;
      }
   }
   switch (suit)
   {
      case clubs:
         cout << static_cast<char>(5);
         break;
      case diamonds:
         cout << static_cast<char>(4);
         break;
      case hearts:
         cout << static_cast<char>(3);
         break;
      case spades:
         cout << static_cast<char>(6);
         break;
   }
}
/////////////////////////////////////////////////////////////////////////////////////////
class player
{
private:
   int nNumber;
   card hand[HAND_SIZE];
   int nIndex;
public:
   player()
   : nNumber(0), nIndex(0)
   {}
   void addCard(const card &crd);
   void getHand();
   void setNumber(int nNum);
   void getPlayerInfo();
};
//---------------------------------------------------------------------------------------
void player::addCard(const card &crd)
{
   if (nIndex < HAND_SIZE)
   {
      hand[nIndex] = crd;
      nIndex++;
   }
}
//---------------------------------------------------------------------------------------
void player::getHand()
{
   for (int i=0; i<HAND_SIZE; i++)
   {
      hand[i].display();
      cout << " ";
   }
}
//---------------------------------------------------------------------------------------
void player::setNumber(int nNum)
{
   nNumber = nNum;
}
//---------------------------------------------------------------------------------------
void player::getPlayerInfo()
{
   cout << "Player number: " << nNumber << endl;
   cout << "Player's hand:" << endl;
   getHand();
   cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   card deck[SIZE];
   int j;
   cout << endl;
   for (j =0; j < SIZE; j++)                                           // make an ordered deck
   {
      int num = (j%HAND_SIZE) +2;                                      // cycles through 2 to 14, 4 times
      Suit su = Suit(j/HAND_SIZE);                                     // cycles through 0 to 3, 13 times
      deck[j].set(num, su);                                            // set card
   }
   cout << "\nOrdered deck:\n";
   for (j=0; j < SIZE; j++)                                            // display ordered deck
   {
      deck[j].display();
      cout << " ";
      if (!((j+1)%HAND_SIZE))                                          // newline every 13 cards
      {
         cout << endl;
      }
   }
   srand(time(NULL));                                                  // seed random numbers with time
   for (j=0; j < SIZE; j++)                                            // for each card in the deck,
   {
      int k = rand() % SIZE;                                           // pick another card at random
      card temp = deck[j];                                             // and swap them
      deck[j] = deck[k];
      deck[k] = temp;
   }
   cout << "\nShuffled deck:\n";
      for (j=0; j < SIZE; j++)                                         // display shuffled deck
   {
      deck[j].display();
      cout << " ";
      if (!((j+1)%HAND_SIZE))                                          // newline every 13 cards
      {
         cout << endl;
      }
   }
   player players[4];
   for (j=0; j<4; j++)
   {
      players[j].setNumber(j+1);
   }
   int i=0;
   for (j=0; j<SIZE; j++)
   {
      players[i++].addCard(deck[j]);
      if (i==4)
      {
         i=0;
      }
   }
   for (j=0; j<4; j++)
   {
      players[j].getPlayerInfo();
   }
   return 0;
}