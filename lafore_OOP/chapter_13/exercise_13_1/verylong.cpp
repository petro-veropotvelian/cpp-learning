// verylong.cpp
// implements very long integer file
#include "verylong.h"                                                          // header file for verylong
//---------------------------------------------------------------------------------------
void verylong::putvl() const                                                   // dislplay verylong
{
   char temp[SZ];
   strcpy(temp, vlstr);                                                        // make a copy
   cout << strrev(temp);                                                       // reverser the copy and display it
}
//---------------------------------------------------------------------------------------
void verylong::getvl()                                                         // get verylong from user
{
   cin >> vlstr;                                                               // get string from user
   vlen = strlen(vlstr);                                                       // find its length
   strrev(vlstr);                                                              // reverse it
}
//---------------------------------------------------------------------------------------
verylong verylong::operator+(const verylong v)                                 // add verylongs
{
   char temp[SZ];
   int j;
   int maxlen = (vlen > v.vlen) ? vlen : v.vlen;                               // find the longest number
   int carry = 0;                                                              // set to 1 if sum >=10
   for (j=0; j<maxlen; j++)                                                    // foreach position
   {
      int d1 = (j > vlen-1) ? 0 : vlstr[j]-'0';                                // get digit
      int d2 = (j > v.vlen-1) ? 0 : v.vlstr[j] -'0';                           // get digit
      int digitsum = d1 + d2 + carry;
      if (digitsum >= 10)                                                      // if there's a carry
      {
         digitsum -=10;                                                        // decrease sum by 10,
         carry = 1;                                                            // set carry to 1
      }
      else
      {
         carry = 0;                                                            // otherwise carry is 0
      }
      temp[j] = digitsum + '0';                                                // insert char in string
   }
   if (carry == 1)                                                             // if carry at end
   {
      temp[j++] = '1';                                                         // last digit is 1
   }
   temp[j] = '\0';                                                             // terminate string
   return verylong(temp);                                                      // return temp verylong
}
//---------------------------------------------------------------------------------------
verylong verylong::operator*(const verylong v)                                 // multiply verylongs
{
   verylong pprod;                                                             // product of one digit
   verylong tempsum;                                                           // running total
   for (int j=0; j < v.vlen; j++)                                              // for each digit in arg
   {
      int digit = v.vlstr[j] - '0';                                            // get the digit
      pprod = multdigit(digit);                                                // multiply this by digit
      for (int k=0; k<j; k++)                                                  // multiply result by
      {                                                                        // by power of 10
         pprod = mult10(pprod);
      }
      tempsum = tempsum + pprod;                                               // add product to total
   }
   return tempsum;                                                             // return total of prods
}
//---------------------------------------------------------------------------------------
verylong verylong::mult10(const verylong v) const                              // multiply arg by 10
{
   char temp[SZ];
   for (int j=v.vlen-1; j>=0; j--)                                             // move digits one positon higher
   {
      temp[j+1] = v.vlstr[j];
   }
   temp[0] = '0';                                                              // put zero on low end
   temp[v.vlen+1] = '\0';                                                      // terminate string
   return verylong(temp);                                                      // return result
}
//---------------------------------------------------------------------------------------
verylong verylong::multdigit(const int d2) const                               // multiply this verylong
{                                                                              // by digit in argument
   char temp[SZ];
   int j, carry = 0;
   for (j=0; j <vlen; j++)                                                     // for each position in this verylong
   {
      int d1 = vlstr[j]-'0';                                                   // get digit from this
      int digitprod = d1 * d2;                                                 // multiply by that digit
      digitprod += carry;                                                      // add old carry
      if (digitprod >= 10)                                                     // if there's a new carry
      {
         carry = digitprod/10;                                                 // carry is high digit
         digitprod -= carry*10;                                                // result is low digit
      }
      else
      {
         carry = 0;                                                            // otherwise carry is 0
      }
      temp[j] = digitprod + '0';                                               // insert char in string
   }
   if (carry !=0)                                                              // if carry at end,
   {
      temp[j++] = carry+ '0';                                                  // it's last digit
   }
   temp[j] = '\0';                                                             // terminate string
   return verylong(temp);                                                      // return verylong
}
//---------------------------------------------------------------------------------------
/*
verylong verylong::operator-(const verylong& v) const {
    char temp[SZ];
    int borrow = 0, j;
    for (j = 0; j < vlen; j++) {
        int d1 = vlstr[j] - '0';
        int d2 = (j < v.vlen) ? v.vlstr[j] - '0' : 0;
        int diff = d1 - d2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[j] = diff + '0';
    }

    // Remove leading zeroes
    while (j > 1 && temp[j - 1] == '0') --j;
    temp[j] = '\0';
    return verylong(temp);
}

verylong verylong::operator/(const verylong& divisor) const {
    verylong result, remainder;
    char quotient[SZ] = {0};
    int q_index = 0;

    for (int i = vlen - 1; i >= 0; --i) {
        char digit_str[2] = {vlstr[i], '\0'};
        verylong digit(digit_str);
        remainder = verylong((strrev((char*)remainder.vlstr)) + strrev(digit.vlstr));
        int count = 0;

        while (!(remainder < divisor)) {
            remainder = remainder - divisor;
            count++;
        }

        quotient[q_index++] = count + '0';
    }

    quotient[q_index] = '\0';
    strrev(quotient);
    return verylong(quotient);
}


verylong verylong::operator+(const verylong& other) const {
    if (isNegative == other.isNegative) {
        verylong result = addAbs(*this, other);
        result.isNegative = isNegative;
        return result;
    } else {
        if (absGreater(*this, other)) {
            verylong result = subtractAbs(*this, other);
            result.isNegative = isNegative;
            return result;
        } else {
            verylong result = subtractAbs(other, *this);
            result.isNegative = other.isNegative;
            return result;
        }
    }
}

verylong addAbs(const verylong&, const verylong&) const;
verylong subtractAbs(const verylong&, const verylong&) const;
bool absGreater(const verylong&, const verylong&) const;

verylong verylong::operator/(const verylong& divisor) const {
    verylong quotient = divideAbs(*this, divisor);
    quotient.isNegative = (isNegative != divisor.isNegative);
    return quotient;
}

void verylong::putvl() const {
    if (isNegative)
        cout << '-';
    char temp[SZ];
    strcpy(temp, vlstr);
    cout << strrev(temp);
}



bool verylong::absGreater(const verylong& a, const verylong& b) const {
    if (a.vlen > b.vlen)
        return true;
    if (a.vlen < b.vlen)
        return false;

    // Same length: compare digit by digit from most significant
    for (int i = a.vlen - 1; i >= 0; --i) {
        if (a.vlstr[i] > b.vlstr[i])
            return true;
        if (a.vlstr[i] < b.vlstr[i])
            return false;
    }
    return false; // Equal magnitudes
}

*/