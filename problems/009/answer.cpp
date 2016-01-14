#include <iostream>
#include <cmath>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This is a simple algorithm to find the pythagorian triplet that sums
 * to 1000. This algorithm runs in linear time O(n) because a and b can be interchanged.
 */

int square(int x) {
  return x*x;
}

int main(){

  int a = 1;
  int b = 1;
  for (a = 1; a < 999; a++){
    for (b = 1; b < 999; b++){
      if ((a + b + sqrt(square(a) + square(b))) == 1000)
      cout << "answer: " << (a * b * sqrt(square(a) + square(b))) << endl;
    }
  }


  return 0;
}
