#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This is a brute force algorithm to ennumerate primes, so that I can
 * discover the 10001st prime number.
 */

bool isPrime(unsigned long long x){
  for (int i = 2; i < x; i++){
    if (x % i == 0) return false;
  }
  return true;
}

int main(){

  cout << "====================== C++ ======================\nhow many primes do you want to generate?\n";
  int primeTarget;
  cin >> primeTarget;
  primeTarget--; // off by one
  int primeCount = 1;

  cout << "1 : 2\n";

  for (unsigned long long i = 3; i < INT_MAX; i+=2){
    if (primeCount > primeTarget) break;
    if (isPrime(i)){
      primeCount++;
      cout << primeCount << " : " << i << "\n";
    }
  }

  return 0;
}
