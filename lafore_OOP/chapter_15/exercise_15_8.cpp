// exercise_15_8.cpp
// You can use the copy() algorithm to copy sequences within a container.
// However, you must be careful when the destination sequence overlaps the
// source sequence. Write a program that lets you copy any sequence to a
// different location within an array, using copy(). Have the user enter
// values for first1, last1, and first2. Use the program to verify that you
// can shift a sequence that overlaps its destination to the left, but not
// to the right. (For example, you can shift several items from 10 to 9,
// but not from 10 to 11.)
// This is because copy() starts with the leftmost element.
#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 20;
void printArray(int* arr, int Size)
{
  cout << "Array: ";
  for (int i=0; i<Size; i++)
  {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int main(int argc, char*argv[])
{
  int src_arr[SIZE];
  for (int i=0; i<SIZE; i++)
  {
    src_arr[i] = i;                                                  // array initialization
  }
  cout << "==> Copy with overlapping demonstartion <==\n";
  cout << "Initial array\n";
  printArray(src_arr, SIZE);
  while (true)
  {
    for (int i=0; i<SIZE; i++)
    {
      src_arr[i] = i;                                                // array re-initialization
    }
    int first1, last1, first2;
    cout << "Enter parameters to copy:" << endl;
    cout << "first1 - the beginning of source (0 - " << (SIZE - 1) << "):";
    cin >> first1;
    if (first1 < 0 )
    {
      break;
    }
    cout << "last1 - the end of source ("<<first1+1 << " - " << SIZE << "):";
    cin >> last1;
    cout << "first2 - the beginning of destination (0 - " << (SIZE -1 )<< "):";
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
    printArray(src_arr, SIZE);
    copy(src_arr + first1, src_arr + last1, src_arr + first2);
    cout << "\nAfter the copying:" << endl;
    printArray(src_arr, SIZE);
    if (IsOverlaps && first2 > first1)
    {
      cout << "Copy shifts elements from left to rigth so when shifting right\n"
           << "new values overwrite elements not copied yet!" << endl;
      cout << "To shift right you need to use copy_backward()." << endl;
    }
    cout << "Specify negative first1 value to exit.";
  }
  cout << "\nBye!";
  return 0;
}