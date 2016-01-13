#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This is a brute force algorithm to find the smallest number that is divisible
 * by the numbers 1-20. I know this can be done in a better way, but done is better than unfinished!
 */

int main(){
  for (int i = 20; i < INT_MAX; i += 2){
      // the check!
      if ((i%3 == 0) &&
          (i%4 == 0) &&
          (i%5 == 0) &&
          (i%6 == 0) &&
          (i%7 == 0) &&
          (i%8 == 0) &&
          (i%9 == 0) &&
          (i%10 == 0) &&
          (i%11 == 0) &&
          (i%12 == 0) &&
          (i%13 == 0) &&
          (i%14 == 0) &&
          (i%15 == 0) &&
          (i%16 == 0) &&
          (i%17 == 0) &&
          (i%18 == 0) &&
          (i%19 == 0) &&
          (i%20 == 0)) cout << i << " << ANSWER!";
  }
  return 0;
}
