#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: This simple algothim that is used to sum the first 2 million primes
 */

 bool isPrime(unsigned long long x){
   for (int i = 3; i < x; i+=2){
     if (x % i == 0) return false;
   }
   return true;
 }

 int main(){

   cout << "====================== C++ ======================\n";
   cout << "count: 1 <> prime: 2\n";
   int primeCount = 1;
   unsigned long long sum = 0;
   for (unsigned long long i = 3; i < INT_MAX; i+=2){
     if (isPrime(i)){
       if (i > 2000000) break; // YOU FOUND IT!
       primeCount++;
       if (primeCount % 5000 == 0) cout << "count: " << primeCount << " <> prime: "<< i << endl; // just to speed it up
       sum += i;
     }
   }
   sum += 2; // because of starting at i=3

   cout << "sum : " << sum << endl;

   return 0;
 }
