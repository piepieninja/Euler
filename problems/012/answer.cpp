#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

int root(int x){
  return (int) sqrt(x) + 1;
}

int enumerateFactors(int x){
  int result = 2;

  return result;
}

int main(){

  int sum = 0;
  int factorNum;
  int target = 500;
  for (int i = 0; i < INT_MAX; i++){
    sum += i;
    int factorNum = enumerateFactors(sum);
    if (factorNum >= target) break;
    cout << i << ": " << sum << " => " << factorNum << endl;
  }

  return 0;
}
