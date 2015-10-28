#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to compute the sum of all even fib numbers
 */

int main(){
  int ret = 0;
  int fib_a = 0;
  int fib_b = 1;
  int fib_c = 1;
  int max = 4000000;
  while (fib_c < max){
    fib_c = fib_a + fib_b;
    fib_a = fib_b;
    fib_b = fib_c;
    if (!(fib_c % 2)) ret += fib_c;
  }
  cout << "answer: " << ret << endl;
  return 0;
}
