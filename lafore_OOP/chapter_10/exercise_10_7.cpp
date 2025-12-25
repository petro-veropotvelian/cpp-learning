// exercise_10_7.cpp
// Modify the person class in the PERSORT program in this chapter so that it
// includes not only a name, but also a salary item of type float representing
// the person's salary.
// You'll need to change the setName() and printName() member functions to
// setData() and printData(), and include in them the ability to set and
// display the salary as well as the name. You'll also need a getSalary()
// function. Using pointer notation, write a salsort() function that sorts the
// pointers in the persPtr array by salary rather than by name. Try doing all
// the sorting in salsort(), rather than calling another function as PERSORT
// does. If you do this, don't forget that -> takes precedence over *, so
// you'll need to say
//     if( (*(pp+j))->getSalary() > (*(pp+k))->getSalary() )
//     { /* swap the pointers */ }
#include <iostream>
#include <string>                                              // for string class
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
class person                                                   // class of persons
{
protected:
   string name;                                                // person's name
   float salary;                                               // person's salary
public:
   void setData()                                              // set the name and salary
   {
      cout << "Enter name: ";
      cin >> name;
      cout << "Enter salary: ";
      cin >> salary;
   }
   void printData()                                            // display the name and salary
   {
      cout << "Name: " << name;
      cout<< "\nSalary, $: " << salary << endl;
   }
   float getSalary()
   {
      return salary;
   }
};
/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   void salsort(person**, int);                                 // prototype
   person* persPtr[100];                                       // array of pointers to persons
   int n = 0;                                                  // number of persons in array
   char choice;                                                // intput char

   do                                                          // put persons in array
   {
      persPtr[n] = new person;                                 // make new object
      persPtr[n]->setData();                                   // set person's name
      n++;                                                     // count new person
      cout << "Enter another (y/n)? ";                         // enter another
      cin >> choice;                                           // person?
   } while(choice == 'y' || choice=='Y');                      // quit on 'n'

   cout << "\nUnsorted list:\n";
   for (int j=0; j<n; j++)                                     // print unsorted list
   {
      persPtr[j]->printData();
   }
   salsort(persPtr, n);
   cout << "\nSorted list:\n";
   for (int j=0; j<n; j++)                                     // print sorted list
   {
      persPtr[j]->printData();
   }
   return 0;
}


//---------------------------------------------------------------------------------------
void salsort(person** pp, int n)                               // sort pointers to persons
{
   for (int j=0; j<n-1; j++)
   {
      for (int k=j+1; k<n; k++)
      {
         if ((*(pp+j))->getSalary() > (*(pp+k))->getSalary())
         {
            person* tempptr = *(pp+j);
            *(pp+j) = *(pp+k);
            *(pp+k) = tempptr;
         }
      }
   }
}
/*
void bsort(person** pp, int n)                                 // sort pointers to persons
{
   void order(person**, person**);                             // prototype
   int j, k;                                                   // indexes to array
   for (j=0; j<n-1; j++)                                       // outer loop
   {
      for (k = j+1; k<n; k++)                                  // inner loop starts at outer
      {
         order(pp+j, pp+k);                                    // order the pointer contents
      }
   }
}
//---------------------------------------------------------------------------------------
void order(person** pp1, person** pp2)                         // orders two pointers if
{                                                              // 1st larger than 2nd
   if ((*pp1)->getName() > (*pp2)->getName())
   {
      person* tempptr = *pp1;                                  // swap the pointers
      *pp1 = *pp2;
      *pp2 = tempptr;
   }
}
*/