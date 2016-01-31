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
int  f1digits     =  0 ; // count the number of digits
int  f2digits     =  0 ; // count the temp
int  f3digits     =  0 ; // count the temp

// put the number x in the fib1
void initFib1(int x){
  f1digits = 0;
  for (int i = 0; x > 0 ; i++){
    fib1[i]  = x%10;
    x /= 10;
    f1digits++;
  }
}

void initFib2(int x){
  f2digits = 0;
  for (int i = 0; x > 0 ; i++){
    fib2[i]  = x%10;
    x /= 10;
    f2digits++;
  }
}

void initFib3(int x){
  f3digits = 0;
  for (int i = 0; x > 0 ; i++){
    fib3[i]  = x%10;
    x /= 10;
    f3digits++;
  }
}

void setFib1(){ // sets fib1 to fib2
  f1digits = f2digits;
  for (int i = 0; i <= f2digits; i++){
    fib1[i] = fib2[i];
  }
}

void setFib2(){ // sets fib2 to fib3
  f2digits = f3digits;
  for (int i = 0; i <= f3digits; i++){
    fib2[i] = fib3[i];
  }
}

void printFib1(){
  cout << "Number: ";
  for (int i = f1digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) fib1[i];
  }
  cout << endl;
}

void printFib2(){
  cout << "Temp: ";
  for (int i = f1digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) fib2[i];
  }
  cout << endl;
}

void add(int x, int fromIndex, bool isTemp){ // adds int x to the array at possition fromIndex
  if (isTemp){
    for (int i = fromIndex; x > 0; i++){
      if (fib2[i] + x%10 < 10) {
	fib2[i] += x%10;
	x /= 10;
      } else { // oh boy here we go
	if (i == f1digits - 1) {
	  f1digits++; // increase digit count and clear previous data
	  fib2[i+1] = 0;
	}
	int val        = (fib2[i] + x%10 - 10);
	int carry      = ((fib2[i] + x%10) / 10);
	fib2[i] = val;
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
	if (i == f1digits - 1) {
	  f1digits++; // increase digit count and clear previous data
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
  for (int i = 0; i < f1digits; i++){
    if (fib2[i] + fib1[i] < 10){
      fib1[i] += fib2[i];
    } else {
      if (i == f1digits - 1){
	f1digits++;
	fib1[i+1] = 0;
      }
      int val   = (fib1[i] + fib2[i]%10 - 10);
      int carry = ((fib1[i] + fib2[i]%10) / 10);
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
  for (int i = 0; i <= f1digits; i++){
    sum += fib1[i];
  }
  cout << "digit sum: " << sum << endl;
}

int main(){

  cout << "========== FIB to 1000  ==========" << endl;

  initNumber(0);



}
