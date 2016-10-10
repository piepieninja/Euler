#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */

// very slow :'(
int divisors(int x){
  int extras = 0;
  if (x == 1) return 1;
  for (int i = 2; i <= sqrt(x); i++){
    if (!(x%i)) extras += 2;
  }
  return (2 + extras);
}

int main(){

  int triangle = 0;
  bool toggle_5 = 1;
  bool toggle_500 = 1;

  for (int i = 1; i < INT_MAX ;i++){
    triangle += i; // counts up the triangular numbers
    if (toggle_5 && divisors(triangle) > 5){
    cout << "over 5: " << triangle << endl;
    toggle_5 = false;
    }
    if (toggle_500 && divisors(triangle) > 500){
      cout << "over 500: " << triangle << endl;
      toggle_500 = false;
      return 0;
    }
    if (i < 0){
      cout << "welp...";
      return 1;
    }
  }
  return 0;
}
