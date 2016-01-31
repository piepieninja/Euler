#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: finding 100! by building very large numbers
 */

char largeNumber[INT_MAX/8] = {0}; // wow this is big
char tempNumber[INT_MAX/8]  = {0}; // wow this is big
char multiplier[65535]      = {0}; // only of size int, 
int  mdigits                =  0 ; // count the int
int  digits                 =  0 ; // count the number of digits


// put the number x in the largeNumber
void initNumber(int x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    largeNumber[i] = x%10;
    //tempNumber[i]  = x%10; // don't do this in production, only for testing
    x /= 10;
    digits++;
  }
}

void initInt(int x){
  mdigits = 0;
  for (int i = 0; x > 0; i++) {
    multiplier[i] = x%10;
    x /= 10;
    mdigits++;
  }
}

void printNumber(){
  cout << "Number: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) largeNumber[i];
  }
  cout << endl;
}

void printMultiplier(){
  cout << "Multiplier: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) multiplier[i];
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
      if (largeNumber[i] + x%10 < 10) {
	largeNumber[i] += x%10;
	x /= 10;
      } else { // oh boy here we go
	if (i == digits - 1) {
	  digits++; // increase digit count and clear previous data
	  largeNumber[i+1] = 0;
	}
	int val        = (largeNumber[i] + x%10 - 10);
	int carry      = ((largeNumber[i] + x%10) / 10);
	largeNumber[i] = val;
	x /= 10;
	x += carry;
      }
    }
  }
}

void add(){ // adds the temp array to the large number array. Need to re-initalize numbers after this
  for (int i = 0; i < digits; i++){
    if (tempNumber[i] + largeNumber[i] < 10){
      largeNumber[i] += tempNumber[i];
    } else {
      if (i == digits - 1){
	digits++;
	largeNumber[i+1] = 0;
      }
      int val   = (largeNumber[i] + tempNumber[i]%10 - 10);
      int carry = ((largeNumber[i] + tempNumber[i]%10) / 10);
      largeNumber[i] = val;
      add(carry, i, 1); // add the left overs!
    }
  }
}

void multiply(int x){
  initInt(x);
  for (int i = 0; i < mdigits; i++){
    for (int j = 0; j < digits; j++ ){
      if (multiplier[i] * largeNumber[j] < 10){
	tempNumber[j] = multiplier[i] * largeNumber[j];
      } else {
	if (j == digits - 1) {
	  digits++;
	  tempNumber[j+1] = 0;
	}
	int val   = (largeNumber[j] * multiplier[i])%10;
	int carry = (largeNumber[j] * multiplier[i])/10;
	tempNumber[j] = val;
	add(carry, j, 1);
      }
    }
  }
  add();
}

int main(){

  cout << "========== FACTORIAL ==========" << endl;

  initNumber(42892);
  printNumber();
  add(2, 0, 0);
  printNumber();
  add(9, 0, 0);
  printNumber();
  add(22222, 0, 0);
  printNumber();


  initNumber(99);
  printNumber();
  add(2, 0, 0);
  printNumber();


  /*initNumber(10);
  printNumber();
  add();
  printNumber();*/

  initNumber(10);
  printNumber();
  multiply(10);
  printMultiplier();
  printNumber();
      
}
