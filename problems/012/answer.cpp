#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

int lookUpTable[INT_MAX] = {0}; 

int root(int x){
  return (int) sqrt(x) + 1;
}

int enumerateFactors(int x){
  int result = 2;
  for (int i = 1; i < (x/2); i++){
    if (!(x%i)) result++;
  }
  return result;
}

int factorLookUp(int x){
  if (!lookUpTable[x]) lookUpTable[x] = enumerateFactors(x);
  return lookUpTable[x];
}

int main(){

  // just for testing
  int currentMax = 0;
  
  int sum = 0;
  int factorNum;
  int target = 500;
  for (int i = 0; i < INT_MAX; i++){
    sum += i;
    int factorNum = factorLookUp[sum];
    if (factorNum >= target) break;
    if (factorNum >= currentMax){
      currentMax = factorNum;
      cout << i << ": " << sum << " => " << factorNum << endl;     
    }
  }
  return 0;
}
