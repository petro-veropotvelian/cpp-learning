//exercise_11_10.cpp
// Carry out the modification, discussed in Exercise 7, to the PARSE program
// of Chapter 10.
// That is, make it possible to parse expressions containing floating-point
// numbers.
// Combine the classes from Exercise 7 with the algorithms from PARSE. You'll
// need to operate on pointers to tokens instead of characters. This involves
// statements of the kind
//    Number* ptrN = new Number(ans);
//    s.push(ptrN);
// and
//    Operator* ptrO = new Operator(ch);
//    s.push(ptrO);
// evaluates arithmetic expressions composed of 1-digit numbers
#include <iostream>
#include <cctype>
#include <cstring>                                             // for strlen(), etc
#include <cmath>

// 8*4-10/2+21/7-1.5*2 =32-5+3-4
// 2+3.5*2-5/2-4
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
            cout << "It ist first operator: " << pToken->getOperator() << endl;
            s.push(pToken);                          // put on stack
         }
         else
         {
            pLastVal = dynamic_cast<Number*>(s.pop());
            pLastOper = dynamic_cast<Operator*>(s.pop());
            if (pToken->getOperator() == '*' || pToken->getOperator()=='/' &&
                pLastOper->getOperator() == '+' || pLastOper->getOperator() == '-')
            {
               cout << "Current operation: " << pToken->getOperator() << endl;
               cout << "Push last operation: " <<pLastOper->getOperator() << endl;
               //bool bIsNegative = false;
               //if (pLastOper->getOperator() == '-')
               //{
               //   bIsNegative = true;
               //}
               s.push(pLastOper);                                 // restore last two pops
               cout << "Push last value: " << pLastVal->getNumber() << endl;
               //if (bIsNegative)
               //{
               //   s.push(new Number(-1.0 * pLastVal->getNumber()));
               //}
               //else
               //{
                  s.push(pLastVal);
               //}
               //bIsNegative = false;
            }
            else                                               // in all other cases
            {
               switch (pLastOper->getOperator())               // do last operation
               {                                               // push result on stack
                  case '+':
                     s.push(new Number(/*fabs(*/s.pop()->getNumber() + pLastVal->getNumber()/*)*/));
                     break;
                  case '-':
                     s.push(new Number(/*fabs(*/s.pop()->getNumber() - pLastVal->getNumber()/*)*/));
                     break;
                  case '*':
                     s.push(new Number(/*fabs(*/s.pop()->getNumber() * pLastVal->getNumber()/*)*/));
                     break;
                  case '/':
                     s.push(new Number(/*fabs(*/s.pop()->getNumber() / pLastVal->getNumber()/*)*/));
                     break;
                  default:
                     cout << "\nUnknown operator";
                     exit(1);
               }   // end switch
            }   // end of all other cases
            cout << "Push operation: " << pToken->getOperator() << endl;
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
   float nNumb;
   const int NTOP = s.gettop();
   Token* arr_token[NTOP];
   int indx = 1;
   cout << "\ns.gettop() = " << s.gettop() << endl;
   while(s.gettop())
   {
      arr_token[NTOP - indx] = s.pop();
      indx++;
   }
   Operator* pOper;
   Number* pNumb;
   bool bRecalculationNeeded = false;
   if ((pOper = dynamic_cast<Operator*>(arr_token[NTOP - 2])) &&
      (pOper->getOperator() == '*' || pOper->getOperator() == '/'))
   {
      bRecalculationNeeded = true;
   }
   if (bRecalculationNeeded)
   {
      cout <<"\nRecalculation is needed!\n";
      Number* pTmpNumb = dynamic_cast<Number*>(arr_token[NTOP - 3]);
      pOper = dynamic_cast<Operator*>(arr_token[NTOP - 2]);
      pNumb = dynamic_cast<Number*>(arr_token[NTOP - 1]);
      cout << pTmpNumb->getNumber() << pOper->getOperator() << pNumb->getNumber() << endl;
      if (pOper->getOperator() == '*')
      {
         s.push(new Number(pTmpNumb->getNumber() * pNumb->getNumber()));
      }
      else if (pOper->getOperator() == '*')
      {
         s.push(new Number(pTmpNumb->getNumber() / pNumb->getNumber()));
      }
   }
   for (int i=NTOP-1; i>=0; --i)
   {
      if (bRecalculationNeeded && i < NTOP-3)
      {
         if (pNumb = dynamic_cast<Number*>(arr_token[i]))
         {
            //s.push(pNumb);
            cout << pNumb->getNumber() << " ";
            s.push(pNumb);
         }
         else if (pOper = dynamic_cast<Operator*>(arr_token[i]))
         {
            cout << pOper->getOperator() << " ";
            s.push(pOper);
         }
      }
      else if (!bRecalculationNeeded)
      {
     // {
      //   if (i < NTOP-3)
     //    {}
     //    e
     // }
     // else
     // {
         if (pNumb = dynamic_cast<Number*>(arr_token[i]))
         {
            //s.push(pNumb);
            cout << pNumb->getNumber() << " ";
            s.push(pNumb);
         }
         else if (pOper = dynamic_cast<Operator*>(arr_token[i]))
         {
            cout << pOper->getOperator() << " ";
            s.push(pOper);
         }
      }
   }
   cout << endl;
   //return -1.0;
   while (s.gettop() > 1)
   {
      pLastVal = dynamic_cast<Number*>(s.pop());                                       // get previous value
      cout << "pLastVal = " << pLastVal->getNumber() << endl;
      switch (s.pop()->getOperator())                                         // get previous operator
      {                                                        // do operation, push answer
         case '+':
            cout << "oper + " << endl;
            nNumb = s.pop()->getNumber();
            cout <<"nNumb = " << nNumb << "pLastVal = " << pLastVal->getNumber() << endl;
            s.push(new Number(/*nNumb + */pLastVal->getNumber() + nNumb));
            break;
         case '-':
            cout << "oper - " << endl;
            nNumb = s.pop()->getNumber();
            cout <<"nNumb = " << nNumb << "pLastVal = "<< pLastVal->getNumber() << endl;
            s.push(new Number(/*nNumb - */pLastVal->getNumber() - nNumb));
            break;
         case '*':
            cout << "oper * " << endl;
            nNumb = s.pop()->getNumber();
            cout <<"nNumb = " << nNumb << "pLastVal = "<< pLastVal->getNumber() << endl;
            s.push(new Number(/*nNumb * */pLastVal->getNumber() * nNumb));
            break;
         case '/':
            cout << "oper / " << endl;
            nNumb = s.pop()->getNumber();
            cout <<"nNumb = " << nNumb << "pLastVal = " << pLastVal->getNumber() << endl;
            s.push(new Number(/*nNumb / */pLastVal->getNumber() / nNumb));
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