// exercise_5_11.cpp
// Write a program, based on the sterling structure of Exercise 10 in
// Chapter 4, that obtains from the user two money amounts in old-style British
// format (£9:19:11), adds them, and displays the result, again in old-style
// format. Use three functions. The first should obtain a
// pounds-shillings-pence value from the user and return the value as a
// structure of type sterling. The second should take two arguments of type
// sterling and return a value of the same type, which is the sum of the
// arguments. The third should take a sterling structure as its argument and
// display its value.
#include <iostream>
#include <Windows.h>
using namespace std;
///////////////////////////////////////////////////////////////////////////////
const int nShillingsInPound = 20;
const int nPenceInShilling = 12;

///////////////////////////////////////////////////////////////////////////////
struct sterling
{
   int pounds;
   int shillings;
   int pence;
   sterling()
   : pounds(0), shillings(0), pence(0)
   {}
};
///////////////////////////////////////////////////////////////////////////////
sterling SetPounds(void);

void GetPounds(const sterling &st);

sterling SummarizePounds(const sterling &stA, const sterling &stB);

///////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   sterling cFirst, cSecond;
   cout << "Enter the first amount\n";
   cFirst = SetPounds();
   cout << "Enter the second amount\n";
   cSecond = SetPounds();
   GetPounds(cFirst);
   cout << endl;
   cout << "+" << endl;
   GetPounds(cSecond);
   cout << endl;
   sterling cResult = SummarizePounds(cFirst, cSecond);
   GetPounds(cResult);
   return 0;
}

//---------------------------------------------------------------------------------------
sterling SetPounds(void)
{
   sterling strl;
   int nPence;
   do
   {
      cout << "Specify amount of pence: ";
      cin >> nPence;
      if (nPence >= nPenceInShilling || nPence < 0)
      {
         system("CLS");
         cout << "Amount of pence shoud be from 0 to " << (nPenceInShilling - 1) << endl;
      }
      else
      {
         strl.pence = nPence;
      }
   } while (nPence >= nPenceInShilling || nPence < 0);
   int nShillings;
   do
   {
      cout << "Specify amount of shillings: ";
      cin >> nShillings;
      if (nShillings >= nShillingsInPound || nShillings < 0)
      {
         system("CLS");
         cout << "Amount of shillings should be from 0 to " << (nShillingsInPound - 1) << endl;
      }
      else
      {
         strl.shillings = nShillings;
      }
   } while (nShillings >= nShillingsInPound || nShillings < 0);
   int nPounds;
   do
   {
      cout << "Specify amout of pounds: ";
      cin >> nPounds;
      if (nPounds < 0)
      {
         system("CLS");
         cout << "Amount of pounds should not be less than 0" << endl;
      }
      else
      {
         strl.pounds = nPounds;
      }
   } while (nPounds < 0);
   return strl;
}
//---------------------------------------------------------------------------------------
void GetPounds(const sterling &st)
{
   cout << '\x9c' << st.pounds << '.' << st.shillings << '.' << st.pence;
}
//---------------------------------------------------------------------------------------
sterling SummarizePounds(const sterling &stA, const sterling &stB)
{
   sterling cResult;
   int nSummPence = stA.pence + stB.pence;
   int nShillings= nSummPence / nPenceInShilling;
   cResult.pence = nSummPence % nPenceInShilling;
   nShillings += stA.shillings + stB.shillings;
   cResult.shillings = nShillings % nShillingsInPound;
   cResult.pounds += nShillings / nShillingsInPound;
   cResult.pounds += (stA.pounds + stB.pounds);
   return cResult;
}