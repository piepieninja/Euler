#include <iostream>
#include "../../lib/LargeNumber.cpp"

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: this is a reuse of code from problem 020 with a data structure that can make very big numbers
 */

int main(){

  cout << "========== FIB to 1000 Digits  ==========" << endl;

  LargeNumber fib1;
  LargeNumber fib2;
  LargeNumber fib3;
  LargeNumber temp;

  fib1.setNumber("1");
  fib2.setNumber("1");
  // fib3.setNumber("1");

  int indexCount = 2;

  while(true){
    temp.setNumber(fib1);
    temp.add(fib2);
    fib3.setNumber(temp);
    fib1.setNumber(fib2);
    fib2.setNumber(fib3);
    indexCount++;
    if (fib3.getDigits() == 1000) break; // get 1000
    cout << "fib " << indexCount << ": "<< fib3.toString() << endl;
  }
  cout << "1000 Digit \nFib " << indexCount << ": "<< fib3.toString() << endl;
}
