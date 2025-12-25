// exercise_7_10.cpp
// A matrix is a two-dimensional array. Create a class matrix that provides the
// same safety feature as the array class in Exercise 7; that is, it checks to
// be sure no array index is out of bounds. Make the member data in the matrix
// class a 10-by-10 array. A constructor should allow the programmer to specify
// the actual dimensions of the matrix (provided they're less than 10 by 10).
// The member functions that access data in the matrix will now need two index
// numbers: one for each dimension of the array. Here's what a fragment of a 
// main() program that operates on such a class might look like:
//    matrix m1(3, 4); // define a matrix object
//    int temp = 12345; // define an int value
//    m1.putel(7, 4, temp); // insert value of temp into matrix at 7,4
//    temp = m1.getel(7, 4); // obtain value from matrix at 7,4
#include <iostream>
using namespace std;

const int ROWS = 10;
const int COLS = 10;
class matrix
{
private:
   int arr[ROWS][COLS];
   int nRowNumb;
   int nColNumb;
public:
   matrix()
   : nRowNumb(ROWS), nColNumb(COLS)
   {}
   matrix(const int nRN, const int nCN)
   {
      if (nRN < 0 || nRN > ROWS)
      {
         cout << "Incorrect value: nuber of rows should be not less than 0 and not greater than " << ROWS << endl;
         nRowNumb = ROWS;
      }
      else
      {
         nRowNumb = nRN;
      }
      if (nCN < 0 || nCN > COLS)
      {
         cout << "Incorrect value: nuber of columns should be not less than 0 and not greater than " << COLS << endl;
         nColNumb = COLS;
      }
      else
      {
         nColNumb = COLS;
      }
   }
   void putel(const int nRow, const int nCol, const int elem);
   int getel(const int nRow, const int nCol);
};

void matrix::putel(const int nRow, const int nCol, const int elem)
{
   if (nRow >=0 && nRow <= (nRowNumb - 1))
   {
      if (nCol >=0 && nCol <= (nColNumb -1))
      {
         arr[nRow][nCol] = elem;
      }
      else
      {
         cout << "Error! Column index must be >= 0 and <= " << nColNumb-1 << endl;
      }
   }
   else
   {
      cout << "Error! Row index must be >= 0 and <= " << nRowNumb-1 << endl;
   }
}

int matrix::getel(const int nRow, const int nCol)
{
   if (nRow >=0 && nRow <= (nRowNumb - 1))
   {
      if (nCol >=0 && nCol <= (nColNumb -1))
      {
         return arr[nRow][nCol];
      }
      else
      {
         cout << "Error! Column index must be >= 0 and <= " << nColNumb-1 << endl;
         return -1;
      }
   }
   else
   {
      cout << "Error! Row index must be >= 0 and <= " << nRowNumb-1 << endl;
      return -1;
   }
}

int main(int argc, char* argv[])
{
   matrix m1(3, 4);
   int temp =12345;
   m1.putel(7, 4, temp);
   temp = m1.getel(7, 4);
   m1.putel(2, 3, temp);
   temp = m1.getel(2, 3);
   return 0;
}