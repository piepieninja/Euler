#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

int lookUpTable[INT_MAX/32] = {0}; 

int enumerateFactors(int x){
  if (lookUpTable[x]) {
    cout << x << " => " << lookUpTable[x] << ",";
    return lookUpTable[x]; // has been calculated so return it
  }
  else { // has not been calculated so find it
    int divisor;
    for (int divisor = 2; divisor <= x; divisor++) {// calculate first convinient divisors
      if (divisor == x) {
	// yippie this is prime! put it in the table!
	lookUpTable[x] = 1;
	cout << "calculated prime: " << x << " => " << lookUpTable[x] << ", ";
	return 1;
	//break;
      }
      if (!(x%divisor)){
	// ok, well let's try this again!
	//cout << ".";
	lookUpTable[divisor] = enumerateFactors(divisor);
	lookUpTable[x/divisor] = enumerateFactors(x/divisor);
	return (lookUpTable[divisor] + lookUpTable[x/divisor]);
      }
    }
    return 0;
  }
}

int factors(int x){ // corrects off by one
  return enumerateFactors(x);
}

void printLookUp(){
  for (int i = 0; i < 32; i++){
    if (!(i%4)) cout << endl;
    cout << "[" << i << " : " << lookUpTable[i] << " ]\t\t";
  }
  cout << endl;
}

int main(){

  // just for testing
  cout << "..." << endl;
  int currentMax = 0;
  lookUpTable[1] = 1;
  
  int sum = 0;
  int factorNum;
  int target = 500;
  int loopRun = 10;//INT_MAX;
  cout << "=======> A Recursive Solution <=======" << endl;
  for (int i = 0; i < loopRun; i++){
    sum += i;
    int factorNum = factors(sum);
    lookUpTable[sum] = factorNum;
    //if (factorNum >= currentMax){
    //  currentMax = factorNum;
    cout << endl << i << ": " << sum << " => " << factorNum << endl << "______________" << endl;     
      //}
  }
  cout << "======= table =======" << endl;
  printLookUp();
  return 0;
}
