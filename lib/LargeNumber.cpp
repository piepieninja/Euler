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
private:
  char   array[100000];
  int    digits;
 public:
  void setNumber(int);
  void setNumber(long);
  void setNumber(string);
  void setNumber(LargeNumber);

  void setValueAtIndex(char, int);

  void decrement();

  void subtract(int);

  void add(int);
  void add(int, int);
  void add(LargeNumber);

  void multiply(int);
  void multiply(LargeNumber);

  void power(int);

  bool equals(int);
  bool equals(LargeNumber);

  char valueAtIndex(int);

  int getDigits();

  long sumDigits();

  string toString();
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
  for (int i = 0; i < digits ; i++){
    array[digits - 1 - i] = str[i] - 48; // assumes ASCII
  }
}

void LargeNumber::setNumber(LargeNumber l){
  digits = l.getDigits();
  for (int i = 0; i < digits; i++){
    this->setValueAtIndex(l.valueAtIndex(i), i);
  }
}

void LargeNumber::setValueAtIndex(char ch, int x){
  array[x] = ch;
}

void LargeNumber::subtract(int x){ // adds int x to the array at possition fromIndex
  for (int i = 0; x > 0; i++){
    if (array[i] - x%10 >= 0) {
      array[i] -= x%10;
      x /= 10;
    } else { // oh boy here we go
      array[i] = 9;
      array[i+1]--;
      if (array[i+1] == 0){
        digits--;
      }
      x /= 10;
    }
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

void LargeNumber::add(int x, int fromIndex){ // adds int x to the array at possition fromIndex
  for (int i = fromIndex; x > 0; i++){
    if (array[i] + x%10 < 10) {
      array[i] += x%10;
      x /= 10;
    } else { // oh boy here we go
    if (i == digits - 1) {
      digits++; // increase digit count and clear previous data
      array[i+1] = 0;
    }
    int val        = (array[i] + x%10 - 10);
    int carry      = ((array[i] + x%10) / 10);
    array[i] = val;
    x /= 10;
    x += carry;
    }
  }
}

void LargeNumber::add(LargeNumber l){
  for (int i = 0; i < digits; i++){
    if (this->valueAtIndex(i) + l.valueAtIndex(i) < 10){
      this->setValueAtIndex(this->valueAtIndex(i) + l.valueAtIndex(i), i);
    } else {
      if (i == digits - 1){
      	digits++;
      	this->setValueAtIndex(0, i + 1);
      }
      int val   = (this->valueAtIndex(i) + l.valueAtIndex(i)%10 - 10);
      int carry = ((this->valueAtIndex(i) + l.valueAtIndex(i)%10) / 10);
      this->setValueAtIndex(val, i);
      this->add(carry, i+1); // add the left overs!
    }
  }
}

void LargeNumber::multiply(int x){
    LargeNumber l;
    l.setNumber(* this);
    x--; // don't multiply by zero!
    while (x){
      this->add(l);
      x--;
    }
}

void LargeNumber::multiply(LargeNumber l){
    LargeNumber temp;
    temp.setNumber(* this);
    l.subtract(1); // don't multiply by zero!
    while (!(l.getDigits() == 1 && l.equals(0))){ // the digits speeds it up
      this->add(temp);
      l.subtract(1);
    }
}

void LargeNumber::power(int x){
  LargeNumber l;
  l.setNumber(* this);
  x--; // don't multiply by zero!
  while (x){
    this->multiply(l);
    x--;
  }
}

// ====== BOOL RETURNS HERE ======
bool LargeNumber::equals(int x){
  LargeNumber l;
  l.setNumber(x);
  if (digits != l.getDigits()) return false; // quick check
  for (int i = 0; i < digits; i++){ // long check
    if (this->valueAtIndex(i) == l.valueAtIndex(i)) return false;
  }
  return true;
}

bool LargeNumber::equals(LargeNumber l){
  //TODO implement
  return false;
}

// ====== char RETURNS HERE ======

char LargeNumber::valueAtIndex(int x){
  return array[x];
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
