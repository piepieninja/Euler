#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: finding 100! by building very large numbers
 */

char largeNumber[INT_MAX/8]  = {0}; // wow this is big
char tempNumber[INT_MAX/8]   = {0}; // wow this is big
int  tdigits                 =  0 ; // count the temp
int  digits                  =  0 ; // count the number of digits


// put the number x in the largeNumber
void initNumber(int x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    largeNumber[i]  = x%10; 
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
    tempNumber[i] = largeNumber[i];
  }
}

void printNumber(){
  cout << "Number: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) largeNumber[i];
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
  initNumber(100);
  while (x) {
    setTemp();
    multiply(x);
    x--;
  }
}

int main(){

  cout << "========== FACTORIAL ==========" << endl;

  factorial(100);
  printNumber();

}
