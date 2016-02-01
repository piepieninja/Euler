#include <iostream>
#include "../../lib/LargeNumber.cpp"

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

int main(){

  cout << "==== PROBLEM 016 ====" << endl;

  LargeNumber large;
  large.binaryPower(1000);
  cout << "2^1000 = " << large.toString() << endl;
  cout << "Digit Sum: " << large.sumDigits() << endl;
}
