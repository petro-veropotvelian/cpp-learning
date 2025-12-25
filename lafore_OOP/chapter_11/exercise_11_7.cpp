// exercise_11_7.cpp
// Remember the PARSE program from Chapter 10? It would be nice to improve this
// program so it could evaluate expressions with real numbers, say type float,
// instead of single-digit numbers. For example:
//    3.14159 / 2.0 + 75.25 * 3.333 + 6.02
// As a first step toward this goal, you need to develop a stack that can hold
// both operators (type char) and numbers (type float). But how can you store
// two different types on a stack, which is basically an array? After all, type
// char and type float aren't even the same size. Could you store pointers to
// different types? They're the same size, but the compiler still won't allow
// you to store type char* and type float* in the same array.
// The only way two different types of pointers can be stored in the same array
// is if they are derived from the same base class. So we can encapsulate a
// char in one class and a float in another, and arrange for both classes to be
// derived from a base class. Then we can store both kinds of pointers in an
// array of pointers to the base class. The base class doesn't need to have any
// data of its own; it can be an abstract class from which no objects will be
// instantiated.
// Constructors can store the values in the derived classes in the usual way,
// but you'll need to use pure virtual functions to get the values back out
// again. Here's a possible scenario:
//    class Token // abstract base class
//    {
//    public:
//       virtual float getNumber()=0; // pure virtual functions
//       virtual char getOperator()=0;
//    };
//    class Operator : public Token
//    {
//    private:
//       char oper; // operators +, -, *, /
//    public:
//       Operator(char); // constructor sets value
//       char getOperator(); // gets value
//       float getNumber(); // dummy function
//    };
//    class Number : public Token
//    {
//    private:
//       float fnum; // the number
//    public:
//       Number(float); // constructor sets value
//       float getNumber(); // gets value
//       char getOperator(); // dummy function
//    };
//    Token* atoken[100]; // holds types Operator* and Number*
// Base-class virtual functions need to be instantiated in all derived classes,
// or the classes themselves become abstract. Thus the Operand class needs a
// getNumber() function, even though it doesn't store a number, and the Number
// class needs getOperand(), even though it doesn't store an operand.
// Expand this framework into a working program by adding a Stack class that
// holds Token objects, and a main() that pushes and pops various operators
// (such as + and *) and floating-point numbers (1.123) on and off the stack.

// evaluates arithmetic expressions composed of 1-digit numbers
#include <iostream>
#include <cctype>
#include <cstring>                                             // for strlen(), etc
using namespace std;
const int LEN = 80;                                            // lenght of expressions, in characters
const int MAX = 40;                                            // size of stack
/////////////////////////////////////////////////////////////////////////////////////////
class Token                                                    // abstract base class
{
public:
   virtual float getNumber() = 0;                              // pure virtual functions
   virtual char getOperator() = 0;
};
/////////////////////////////////////////////////////////////////////////////////////////
class Operator : public Token
{
private:
   char oper;                                                  // operator +, -, *, /
public:
   Operator(char);                                             // constructor sets value
   char getOperator();                                         // gets value
   float getNumber();                                          // dummy function
};
//---------------------------------------------------------------------------------------
Operator::Operator(char c)
: oper(c)
{}
//---------------------------------------------------------------------------------------
char Operator::getOperator()
{
   return oper;
}
//---------------------------------------------------------------------------------------
float Operator::getNumber()
{
   return -1;
}
/////////////////////////////////////////////////////////////////////////////////////////
class Number : public Token
{
private:
   float fnum;                                                 // the number
public:
   Number(float);                                              // constructor sets value
   float getNumber();                                          // gets value
   char getOperator();                                         // dummy function
};
//---------------------------------------------------------------------------------------
Number::Number(float fl)
: fnum(fl)
{}
//---------------------------------------------------------------------------------------
float Number::getNumber()
{
   return fnum;
}
//---------------------------------------------------------------------------------------
char Number::getOperator()
{
   return '\0';
}
/////////////////////////////////////////////////////////////////////////////////////////
class Stack
{
private:
   Token* atoken[MAX];                                         // stack: array of tokens (holds types Operator* an Number*)
   int top;                                                    // number of top of stack
public:
   Stack()                                                     // constructor
   {
      top =0;
   }
   void push(Token* var)                                         // put char on stack
   {
      atoken[++top]= var;
   }
   Token* pop()                                                  // take char off stack
   {
      return atoken[top--];
   }
   int gettop()                                                // get top of stack
   {
      return top;
   }
};

/////////////////////////////////////////////////////////////////////////////////////////
class express                                                  // expression class
{
private:
   Stack s;                                                    // stack for analysis
   char* pStr;                                                 // pointer to input string
   int len;                                                    // length of input string
public:
   express(char* ptr)                                          // constructor
   {
      pStr = ptr;                                              // set pointer to string
      len = strlen(pStr);                                      // set length
   }
   void parse();                                               // parse the input string
   float solve();                                                // evaluate the stak
   bool IsOperator(char ch);
};
//---------------------------------------------------------------------------------------
bool express::IsOperator(char ch)
{
   if (ch=='+' || ch =='-' || ch=='*' || ch=='/')
   {
      return true;
   }
   return false;
}
//---------------------------------------------------------------------------------------
void express::parse()                                          // add items to stack
{
   Token* pToken;
   Number* pLastVal;
   Operator* pLastOper;
   for (int i=0; i< len; i++)
   {
      if (IsOperator(pStr[i]))
      {
         pToken = new Operator(pStr[i]);
      }
      else
      {
         char strNumber[MAX];
         int indx = 0;
         do
         {
            if (isdigit(pStr[i])|| pStr[i]=='.')
            {
               strNumber[indx++] = pStr[i];
            }
         } while (++i < len && !IsOperator(pStr[i]));
         --i;
         strNumber[indx] = '\0';
         float fnumb = static_cast<float>(atof(strNumber));
         pToken = new Number(fnumb);
      }
      Operator* pOperat;
      Number* pNumb;
      if (pNumb = dynamic_cast<Number*>(pToken))
      {
         cout << "Push numeric value: " << pToken->getNumber() << endl;
         s.push(pToken);                              // save numerical value_type
      }
      else if (pOperat = dynamic_cast<Operator*>(pToken))
      {
         if (s.gettop() == 1)                         // if it's first operator
         {
            //cout << "It ist first operator: " << pToken->getOperator() << endl;
            s.push(pToken);                          // put on stack
         }
         else
         {
            pLastVal = dynamic_cast<Number*>(s.pop());
            pLastOper = dynamic_cast<Operator*>(s.pop());
            if (pToken->getOperator() == '*' || pToken->getOperator()=='/' &&
                pLastOper->getOperator() == '+' || pLastOper->getOperator() == '-')
            {
               cout << "Push last operation: " <<pLastOper->getOperator() << endl;
               
               s.push(pLastOper);                                 // restore last two pops
               cout << "Push last value: " << pLastVal->getNumber() << endl;
               s.push(pLastVal);
            }
            else                                               // in all other cases
            {
               switch (pLastOper->getOperator())               // do last operation
               {                                               // push result on stack
                  case '+':
                     s.push(new Number(s.pop()->getNumber() + pLastVal->getNumber()));
                     break;
                  case '-':
                     s.push(new Number(s.pop()->getNumber() - pLastVal->getNumber()));
                     break;
                  case '*':
                     s.push(new Number(s.pop()->getNumber() * pLastVal->getNumber()));
                     break;
                  case '/':
                     s.push(new Number(s.pop()->getNumber() / pLastVal->getNumber()));
                     break;
                  default:
                     cout << "\nUnknown operator";
                     exit(1);
               }   // end switch
            }   // end of all other cases
            s.push(pToken);   // put current operation on stack
         }   // end not first operator
      }   // end else in a Operator
      else    // not a known character
      {
         cout << "\nUnknown input character";
         exit(1);
      }
   }   // end of for() loop
}// end parse()
//---------------------------------------------------------------------------------------
float express::solve()                                           // remove items from stack
{
   Number* pLastVal;                                               // previous value
   while (s.gettop() > 1)
   {
      pLastVal = dynamic_cast<Number*>(s.pop());                                       // get previous value
      switch (s.pop()->getOperator())                                         // get previous operator
      {                                                        // do operation, push answer
         case '+':
            s.push(new Number(s.pop()->getNumber() + pLastVal->getNumber()));
            break;
         case '-':
            s.push(new Number(s.pop()->getNumber() - pLastVal->getNumber()));
            break;
         case '*':
            s.push(new Number(s.pop()->getNumber() * pLastVal->getNumber()));
            break;
         case '/':
            s.push(new Number(s.pop()->getNumber() / pLastVal->getNumber()));
            break;
         default:
            cout << "\nUnknown operator";
            exit(1);
      }// end swithch
   }// end while
   //return int(s.pop());                                         // last item on stack is answer
   return s.pop()->getNumber();                                   // last item on stack is answer
} // end solve()

/////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
   char ans;                                                   // 'y' or 'n'
   char string[LEN];                                           // input string from user

   cout << "\nEnter an arithmetic experssion"
           "\nof the form 2+3*4/3-2."
           "\nNo number may have more than one digit."
           "\nDon't use any spaces of parentheses.";
   do
   {
      cout << "\nEnter expression: ";
      cin >> string;                                            // input from user
      express* eptr = new express(string);                     // make expression
      eptr->parse();                                           // parse it
      cout << "\nThe numerical value is: " << eptr->solve();   // solve it
      delete eptr;                                             // delete expression
      cout << "\nDo another (Enter y or n)? ";
      cin >> ans;
   } while (ans =='y' || ans =='Y');
   return 0;
}