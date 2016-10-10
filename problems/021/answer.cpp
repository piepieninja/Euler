#include <iostream>
#include <math.h>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

 int sumOfDivisors(int x){
   int sum = 0;
   if (x == 1) return 1;
   for (int i = 2; i <= sqrt(x); i++){
     if (!(x%i)){
       sum += i;     // the small ones
       sum += (x/i); // the big ones
     }
   }
   return (sum + 1);
 }

 int main(){

   int sum = 0;
   int j = 0;
   for (int i = 0; i < 10000; i++){
     j = sumOfDivisors(i);
     if (sumOfDivisors(j) == i && i != j){
       cout << "is amicable: " << i << endl;
       sum += i;
     }
   }

   cout << "sum: " << sum << endl;



   return 0;
 }
