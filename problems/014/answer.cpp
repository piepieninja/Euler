#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

bool isPow2(long x){
  return (x && !(x & (x - 1))); // black magic. nah jk, just math!
}

long max(long x, long y){
  if (x > y) return x;
  return y;
}

int produceChain(long x){
  bool p = 0;
  int ret = 0;

  while (x != 1){
      if (p) cout << x << " ~> ";
      if (x%2){ // odd number
        x = 3*x + 1;
      } else { // even number
        x /= 2;
      }
      ret++;
  }
  if (p) cout << "1" << endl;
  return (ret + 1);
}


int main(){

  long largest = 0;
  long test = 0;
  int index = 0;
  for (long i = 1; i < 1000000; i++){
    if (!isPow2(i) && (i%10)){ // determines if it's worth calulating this... sometimes it is not! kinda making a bet here...
      // cout << "length of " << i << " = "<< produceChain(i) << endl; // in case we want a fun little print
      test = produceChain(i);
      if (test > largest){
        index = i;
        largest = test;
      }
    }
  }

  cout << "largest found: " << test << ", at index: " << index << endl;

  return 0;
}
