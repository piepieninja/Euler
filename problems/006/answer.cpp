#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription: this are general perpous algorithms for finding the sum of squares and
 * the square of sums. This is a brute force approch that takes O(n^2) time.
 */

unsigned long long square(unsigned long long x){
  return x*x;
}

unsigned long long sum_of_squares(unsigned long long low, unsigned long long high) {
  high++; // because off by 1
  unsigned long long result = 0;
  for (low; low < high; low++){
    result += square(low);
  }
  return result;
}

unsigned long long square_of_sums(unsigned long long low, unsigned long long high){
  high++; // because off by 1
  unsigned long long result = 0;
  for (low; low < high; low++){
    result += low;
  }
  return square(result);
}

int main() {
  cout << "====================== C++ ======================\n";
  unsigned long long sum_sqr = sum_of_squares(0, 100);
  cout << "sum of squares: " << sum_sqr << "\n";
  unsigned long long sqr_sum = square_of_sums(0, 100);
  cout << "square of sums: " << sqr_sum << "\n";

  unsigned long long result = sqr_sum - sum_sqr;

  cout << "result: " << result << "\n";

  return 0;
}
