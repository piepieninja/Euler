#include <iostream>
#include <cmath>

using namespace std;

__device int pow(int x, int n){
  while (n != 0){
    x *= x;
    n--;
  }
  return x;
}

// the actual verifier is here
__global__ void double_pal_verify(int *in, int *out, int n){
  // the number we are testing
  int num = blockIdx.x*blockDim.x+threadIdx.x;
  // is it zero? 
  if (!num) { out[0] = 0; return; }
  bool dig;
  if (num < 10) { out[num] = num; return; }
  
  // check if the int is a palindrome
  int temp = num;
  int rmdr, test;
  while (num > 0){
    rmdr = temp % 10;
    test = 10 * test + r;
    temp = temp % 10;
  }
  if (num == test){
    out[num] = num;
    return;
  } else {
    out[num] = 0;
    return;
  }

  // check if the bool is a palindrome
  if (num >= pow()){
    // wow this has 20 digits in binary! 
  } else if () {

  }

}

int main(){
    cout << "PROBLEM 36 SOLUTION" << endl;
    // vector size
    int n = 1000000;

    return 0;
}

