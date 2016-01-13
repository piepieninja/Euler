#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This a brute force approach to finding the largest pallendrome of two 3-digit multiples
 * This algorithm operates in O(n^2) time
 * Method: isPallandrome. returns 1 if so and 0 if not!
 */


bool isPallandrome(int x){
  int reverse = 0;
  int n = x;
  while (n != 0){
    reverse = reverse * 10;
    reverse = reverse + n%10;
    n       = n/10;
  }
  return (x == reverse);
}

int main(){
  int max_pall = 0;
  for (int i = 999; i > 100; i--){
    for (int j = 999; j > 100; j--){
      if (isPallandrome(i*j) && (i*j > max_pall) ) {
        max_pall = i * j;
        cout << i << " * " << j << " = " << max_pall << "\n";
        // will eventually find the largest
      }
    }
  }
  return 0;
}
