// exercise_10_3.cpp
// Start with an array of pointers to strings representing the days of the
// week, as found in the PTRTOSTR program in this chapter. Provide functions
// to sort the strings into alphabetical order, using variations of the bsort()
// and order() functions from the PTRSORT program in this chapter. Sort the
// pointers to the strings, not the actual strings.
#include <iostream>
#include <cstring>
using namespace std;
const int DAYS = 7;

int main(int argc, char* argv[])
{
   void bsort(char** ptr, int n); // prototype
    //array of pointers to char
   char* arrptrs[DAYS] = { "Sunday", "Monday", "Tuesday",
                           "Wednesday", "Thursday",
                           "Friday", "Saturday"  };
   cout << "Before the call bsort():\n";
   for(int j=0; j<DAYS; j++)    //display every string
   {
      cout << arrptrs[j] << endl;
   }
   bsort(arrptrs, DAYS);
   cout << "After the call bsort():\n";
   for(int j=0; j<DAYS; j++)    //display every string
   {
      cout << arrptrs[j] << endl;
   }
   return 0;
}

//--------------------------------------------------------------
void bsort(char** ptr, int n)
   {
   void order(char**, char**);      //prototype
   int j, k;                    //indexes to array

   for(j=0; j<n-1; j++)         //outer loop
      for(k=j+1; k<n; k++)      //inner loop starts at outer
   order(ptr+j, ptr+k);         //order the pointer contents
   }
//--------------------------------------------------------------
void order(char** numb1, char** numb2)  //orders two numbers
   {                               
      if (strcmp(*numb1, *numb2)> 0)          //if 1st larger than 2nd,
      {
      char *temp = *numb1;        //swap them
      *numb1 = *numb2;
      *numb2 = temp;
      }
   }