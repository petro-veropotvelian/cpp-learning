// exercise_15_12.cpp
// A frequency table lists words and the number of times each word appears in
// a text file.
// Write a program that creates a frequency table for a file whose name is
// entered by the user. You can use a map of string-int pairs. You may want to
// use the C library function ispunct() (in header file CTYPE.H) to check for
// punctuation so you can strip it off the end of a word, using the string
// member function substr(). Also, the tolower() function may prove handy for
// uncapitalizing words.
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <unordered_map>
using namespace std;

string strip_punct(const string &strInput)
{
   size_t start=0, end = strInput.size();
   while (start<end && ispunct(static_cast<unsigned char>(strInput[start])))
   {
      ++start;
   }
   while (end>start && ispunct(static_cast<unsigned char>(strInput[end-1])))
   {
      --end;
   }
   return strInput.substr(start, end-start);
}

string string_to_lower(const string &strInput)
{
   string strOut = strInput;
   transform(strOut.begin(), strOut.end(), strOut.begin(), [](unsigned char ch)
                                                            { return tolower(static_cast<char>(ch)); });
   return strOut;
}

int main(int argc, char* argv[])
{
   // get filename from user
   string strFileName;
   cout << "Please, specify name of the text file you'd like to read: ";
   cin >> strFileName;
   ifstream inFile;
   // open file, specified by user
   inFile.open(strFileName);
   if (!inFile)
   {
      cerr << "\nError! Can't open " << strFileName << endl;
      exit(-1);
   }
   string line;
   unordered_map<string, int> freq_dict;
   // read text file, specified by user
   while (getline(inFile, line))                                     // read the line
   {
      istringstream iss(line);
      string token;
      while (iss>>token)                                             // break the line into separate words
      {
         token = strip_punct(token);
         if (token.empty())
         {
            continue;
         }
         token = string_to_lower(token);
         ++freq_dict[token];
      }
   }
   cout << "\nThe results of work (word : its frequency):\n";
   for (auto pr : freq_dict)
   {
      cout << pr.first << " : " << pr.second << endl; 
   }
   cout << "\nBye!" << endl;
   return 0;
}