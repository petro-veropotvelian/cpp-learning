// exercise_15_11.cpp
// Write a program that copies a source file of integers to a destination file,
// using stream iterators. The user should supply both source and destination
// filenames to the program.
// You can use a while loop approach. Within the loop, read each integer value
// from the input iterator and write it immediately to the output iterator,
// then increment both iterators.
// The ITER.DAT file created by the FOUTITER program in this chapter makes a
// suitable source file.
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <process.h>
#include <iterator>
#include <algorithm>

#define DEBUG
using namespace std;


int main(int argc, char* argv[])
{
   string strSrcFileName;
   cout << "Please, specify source filename: ";
   cin >> strSrcFileName;
   list <int> l_Buff;
   ifstream infile;
   infile.open(strSrcFileName);
   if (!infile)
   {
      cerr << "\nError! Can't open " << strSrcFileName << endl;
      exit(-1);
   }
   istream_iterator<int> fin_iter(infile);
   istream_iterator<int> end_of_stream;
   copy(fin_iter, end_of_stream, back_inserter(l_Buff));
   if (l_Buff.empty())
   {
      cerr << "\nBuffer is empty. Nothing was read from the file!" << endl;
      exit(-2);
   }
   else
   {
      cout << "The contents of the file were successfully read.\n"
            << "Please, specify the name of the target file were the data should be written: ";
      string strDstFileName;
      cin >> strDstFileName;
      ofstream outfile;
      outfile.open(strDstFileName);
      if (!outfile)
      {
         cerr << "\nError! Can't open " << strDstFileName << endl;
         exit(-3);
      }
      ostream_iterator<int> ositer(outfile, " ");
      copy(l_Buff.begin(), l_Buff.end(), ositer);
      #ifdef DEBUG
      {
         ostream_iterator<int> out_print(cout, ", ");
         copy(l_Buff.begin(), l_Buff.end(), out_print);
         cout << endl;
      }
      #endif
   }
   cout <<"\nBye!"<< endl;
   return 0;
}