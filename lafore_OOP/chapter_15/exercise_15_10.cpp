// exercise_15_10.cpp
// You can use the copy_backward() algorithm to overcome the problem described
// in Exercise 7 (that is, you can’t shift a sequence to the left if any of the
// source overlaps any of the destination). Write a program that uses both 
// copy() and copy_backward() to enable shifting any sequence anywhere within a
// container, regardless of overlap.

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

const int SIZE = 20;

void initArray(array<int, SIZE> &arr)
{
   for (int i=0; i<SIZE; i++)
   {
      arr[i] = i;
   }
}
//---------------------------------------------------------------------------------------
void printArray(array<int, SIZE> arr)
{
   cout << "Array: ";
   for (int i=0; i<SIZE; i++)
   {
      cout << arr[i] << ' ';
   }
   cout << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char*argv[])
{
   array<int, SIZE> src_arr;
   cout << "==> Copy with overlapping demonstartion <==\n";
   cout << "Initial array\n";
   initArray(src_arr);
   printArray(src_arr);
   while (true)
   {
      initArray(src_arr);                                            // array re-initialization
      int first1, last1, first2;
      cout << "Enter parameters to copy:";
      cout << "\nfirst1 - the beginning of the source  (0 - " << SIZE-1 <<"): ";
      cin >> first1;
      if (first1 < 0 )
      {
         break;                                                      // exit the program
      }
      cout << "last1 - the end of the source (" << first1 << " - " << SIZE << "): ";
      cin >> last1;
      cout << "first2 - the beginning of the destination (0 - " << SIZE-1 << "): ";
      cin >> first2;
      if (first1 <0 || first1>= SIZE-1 || last1 <= first1 ||
          last1 > SIZE || first2 < 0 || first2 >= SIZE-1)
      {
         cout << "\nIncorrect parameters! Try again.\n";
         continue;
      }
      int length = last1 - first1;
      if (first2 + length > SIZE)
      {
         cout << "\nError! Destination is out of bounds of the array!\n";
         continue;
      }
      cout <<"\n--- Operation analysis ---\n";
      cout << "We are trying to copy elements [" << first1 << "," << last1 <<") into the position " << first2;
      cout << "\nThe length of the sequence is " << length << endl;
      bool IsOverlaps = ((first2 > first1 && first2 < last1) || 
                         (first1 > first2 && first1 < (first2 + length))) ;
      if (IsOverlaps)
      {
         cout << "\nCaution! Sequences are overlapsed!" << endl;
         if (first1 > first2)
         {
            cout << "\nLeft shift (safe for COPY)" << endl;
         }
         else
         {
            cout << "\nRight shift (dangerous for COPY)" << endl;
         }
      }
      else
      {
         cout << "\nSAFE: sequences are not overlaplsed." << endl;
      }
      cout << "\nBefore copying:" << endl;
      printArray(src_arr);
      copy(begin(src_arr) + first1, begin(src_arr) + last1, begin(src_arr) + first2);
      cout << "\nAfter the copying:" << endl;
      printArray(src_arr);
      if (IsOverlaps && first2 > first1)
      {
         cout << "Copy shifts elements from left to rigth so when shifting right\n"
              << "new values overwrite elements not copied yet!" << endl;
         cout << "To shift right you need to use copy_backward()." << endl;
         initArray(src_arr);
         copy_backward(begin(src_arr) + first1, begin(src_arr) + last1, begin(src_arr) + first2);
         cout << "After the using copy_backward():\n";
         printArray(src_arr);
      }
      cout << "Specify negative first1 value to exit." << endl;
   }
   cout << "Bye!" << endl;
   return 0;
}