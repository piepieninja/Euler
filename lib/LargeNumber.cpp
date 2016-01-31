#include <iostream>
#include <sstream>
#include <string>

/**
 * LargeNumber Class
 * These are numbers of 100,000 digits
 * MAX LargeNumber is 10^(100,000)
 *
 */

using namespace std;

class LargeNumber{
  char   array[100000];
  int    digits;
 public:
  void setNumber(int);
  void setNumber(long);
  void setNumber(string);

  void add(int);
  void add(string);

  int getDigits();

  long sumDigits();

  string toString();
  string getDigits(int);
};

// ====== VOID RETURNS HERE ======

void LargeNumber::setNumber(int x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    array[i]  = x%10;
    x /= 10;
    digits++;
  }
}

void LargeNumber::setNumber(long x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    array[i]  = x%10;
    x /= 10;
    digits++;
  }
}

void LargeNumber::setNumber(string str){
  digits = str.length();
  for (int i = 0; i < digits; i++){
    array[i] = str[i] - 48; // assumes ASCII
  }
}

void LargeNumber::add(int x){ // adds int x to the array at possition fromIndex
  for (int i = 0; x > 0; i++){
    if (array[i] + x%10 < 10) {
      array[i] += x%10;
      x /= 10;
    } else { // oh boy here we go
    if (i == digits - 1) {
      digits++; // increase digit count and clear previous data
      array[i+1] = 0;
    }
    int val       = (array[i] + x%10 - 10);
    int carry     = ((array[i] + x%10) / 10);
    array[i] = val;
    x /= 10;
    x += carry;
    }
  }

}

void LargeNumber::add(string str){
  // TODO implement this
}

// ====== INT RETURNS HERE ======

int LargeNumber::getDigits(){
  return digits;
}

// ====== LONG RETURNS HERE ======

long LargeNumber::sumDigits(){
  // the largest this could be is 9 * 100,000 so only a long is need. LONG_MAX is 2147483647 (2^(31)-1) or greater
  long sum = 0;
  for (int i = 0; i < digits; i++){
    sum += array[i];
  }
  return sum;
}

// ====== STRING RETURNS HERE ======

string LargeNumber::toString(){
  ostringstream os;
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    os << (int) array[i];
  }
  return os.str();
}

/**
* return the first |x| digits if x > 0 and the last |x| digits if x < 0
*/
string LargeNumber::getDigits(int x){
  // TODO implement
  ostringstream os;
  if (x > 0) {
    for (int i = 0; i < x; i++){ // print it backwards
      os << (int) array[digits - 1 - i];
    }
  } else {
    for (int i = 0; i < (x * -1); i++){ // print it backwards
      os << (int) array[i];
    }
  }
  return os.str();
}
