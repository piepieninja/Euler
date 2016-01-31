#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: finding 100! by building very large numbers
 */

char largeNumber[INT_MAX/8] = {0}; // wow this is big
char tempNumber[INT_MAX/8] = {0}; // wow this is big
int  digits                 =  0 ; // count the number of digits


// put the number x in the largeNumber
void initNumber(int x){
  digits = 0;
  for (int i = 0; x > 0 ; i++){
    largeNumber[i] = x%10;
    tempNumber[i]  = x%10;
    x /= 10;
    digits++;
  }
}

void printNumber(){
  cout << "Number: ";
  for (int i = digits - 1; i >= 0; i--){ // print it backwards
    cout << (short) largeNumber[i];
  }
  cout << endl;
}

void add(){

}

void add(int x, int fromIndex, bool isTemp){ // adds int x to the array at possition fromIndex
  if (isTemp){
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

void multiply(int x){
  for (int i = 0; x > 0; i++){
    
  }
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


  initNumber(10);
  printNumber();
  multiply(10);
  printNumber();
  
}
