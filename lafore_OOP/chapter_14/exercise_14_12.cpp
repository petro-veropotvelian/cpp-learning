// exercise_14_12.cpp
// Sometimes the easiest way to use exceptions is to create a new class of which
// an exception class is a member. Try this with a class that uses exceptions to
// handle file errors.
// Make a class dofile that includes an exception class and member functions to
// read and write files. A constructor to this class can take the filename as an
// argument and open a file with that name. You may also want a member function
// to reset the file pointer to the beginning of the file. Use the REWERR program
// in Chapter 12 as a model, and write a main() program that provides the same
// functionality, but does so by calling on members of the dofile class.

#include <fstream>                                                   // for file streams
#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;
//int buff[MAX];

class dofile
{
private:
   fstream file_st;
public:
   class fileException
   {
      public:
      string str_cause;
      fileException(string st)
      : str_cause(st)
      {}
   };
   dofile(const char* filename)
   {
      file_st.open(filename, ios::trunc | ios::in | ios::out | ios::binary);
      if (!file_st)
      {
         string str = "Could not open output file ";
         str+= filename;
         throw dofile::fileException(str);
      }
   }
   ~dofile()
   {
      if (file_st)
      {
         file_st.close();
      }
   }
   void read_data(int* pArr, const int nSize)
   {
      file_st.read(reinterpret_cast<char*>(pArr), nSize*sizeof(int));
      if (!file_st)
      {
         throw dofile::fileException("Could not read from file");
      }
   }
   void write_data(int* pArr, const int nSize)
   {
      file_st.write(reinterpret_cast<char*>(pArr), nSize*sizeof(int));
      if (!file_st)
      {
         throw dofile::fileException("Could not write to file");
         exit(1);
      }
   }
   void reset_fp()
   {
      if (file_st)
      {
         file_st.seekg(0);
      }
   }
};
int main(int argc, char* argv[])
{
   int buff[MAX];
   for (int i=0; i<MAX; i++)                                         // fill in the buffer
   {
      buff[i] = 10 * (i+1);
   }
   int buff_copy[MAX];                                               // another array
   try
   {
      dofile dF("tempfile.dat");
      dF.write_data(buff, MAX);                                      // write data to file
      dF.reset_fp();                                                 // reset file pointer
      dF.read_data(buff_copy, MAX);                                  // read data from file to another buffer
      for (int j=0; j<MAX; j++)
      {
         cout << "buff_copy[" << j << "] = " <<buff_copy[j] << endl;
      }
   }
   catch (dofile::fileException fEx)
   {
      cerr << "\nException: " << fEx.str_cause << endl;
   }
   cout << "The program completed successfully." << endl;
   return 0;
}