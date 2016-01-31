#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: this is a reuse of code from problem 020 with a data structure that can make very big numbers
 */

char fib1[1002]   = {0}; // wow this is big // use INT_MAX if you want
char fib2[1002]   = {0}; // wow this is big
char fib3[1002]   = {0}; // wow this is big
int  tdigits      =  0 ; // count the temp
int  digits       =  0 ; // count the number of digits


// put the number x in the fib1
void initNumber(int x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    fib1[i]  = x%10;
    x /= 10;
    digits++;
  }
}

void initTemp(int x){
  tdigits = 0;
  for (int i = 0; x > 0 ; i++){
    tempNumber[i]  = x%10;
    x /= 10;
    tdigits++;
  }
}

void setTemp(){ // set the temp to the number
  tdigits = digits;
  for (int i = 0; i <= digits; i++){
    tempNumber[i] = fib1[i];
  }
}

void printNumber(){
  cout << "Number: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) fib1[i];
  }
  cout << endl;
}

void printTemp(){
  cout << "Temp: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) tempNumber[i];
  }
  cout << endl;
}

void add(int x, int fromIndex, bool isTemp){ // adds int x to the array at possition fromIndex
  if (isTemp){
    for (int i = fromIndex; x > 0; i++){
      if (tempNumber[i] + x%10 < 10) {
	tempNumber[i] += x%10;
	x /= 10;
      } else { // oh boy here we go
	if (i == digits - 1) {
	  digits++; // increase digit count and clear previous data
	  tempNumber[i+1] = 0;
	}
	int val        = (tempNumber[i] + x%10 - 10);
	int carry      = ((tempNumber[i] + x%10) / 10);
	tempNumber[i] = val;
	x /= 10;
	x += carry;
      }
    }
  } else {
    for (int i = fromIndex; x > 0; i++){
      if (fib1[i] + x%10 < 10) {
	fib1[i] += x%10;
	x /= 10;
      } else { // oh boy here we go
	if (i == digits - 1) {
	  digits++; // increase digit count and clear previous data
	  fib1[i+1] = 0;
	}
	int val        = (fib1[i] + x%10 - 10);
	int carry      = ((fib1[i] + x%10) / 10);
	fib1[i] = val;
	x /= 10;
	x += carry;
      }
    }
  }
}

void add(){ // adds the temp array to the large number array. Need to re-initalize numbers after this
  for (int i = 0; i < digits; i++){
    if (tempNumber[i] + fib1[i] < 10){
      fib1[i] += tempNumber[i];
    } else {
      if (i == digits - 1){
	digits++;
	fib1[i+1] = 0;
      }
      int val   = (fib1[i] + tempNumber[i]%10 - 10);
      int carry = ((fib1[i] + tempNumber[i]%10) / 10);
      fib1[i] = val;
      add(carry, i+1, 0); // add the left overs!
    }
  }
}

void multiply(int x){
  x--; // let's not count zero
  while(x) {
    add();
    x--;
  }
}

void factorial(int x){
  initNumber(x);
  while (x) {
    setTemp();
    multiply(x);
    x--;
  }
}

void sumDigits(){
  long sum = 0;
  for (int i = 0; i <= digits; i++){
    sum += fib1[i];
  }
  cout << "digit sum: " << sum << endl;
}

int main(){

  cout << "========== FIB to 1000  ==========" << endl;

  initNumber(0);


}
