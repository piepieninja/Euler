#include <iostream>
#include <cmath>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to list the prime factors of a number.
 */

int main(){

  unsigned long long target = 600851475143;

  while (!(target % 2)) {
    cout << "2 ";
    target /= 2;
  }

  for (int i = 3; i <= sqrt(target); i += 2){
    while (!(target % i)){
      cout << i << " ";
      target = target/i;
    }
  }

  if (target > 2) cout << target << "";

  cout << "\n";

  return 0;
}
