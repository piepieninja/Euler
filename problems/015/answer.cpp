#include <iostream>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */


long countPaths(int x, int y){
  // because of the special case of our problem:
  x++;
  y++;

  long counted[x][y];

  for (int i = 0; i < x; i++){ // put 1's in all the x = 0;
    counted[i][0] = 1;
  }
  for (int j = 0; j < y; j++){ // put 1's in all the y = 0;
    counted[0][j] = 1;
  }

  for (int i = 1; i < x; i++){ // start after the 1's
    for (int j = 1; j < y; j++){ // start after the 1's
      // the paths to each area is equal to the sum of the possilbe paths of the ares to the left and above that area:
      counted[i][j] = counted[i-1][j] + counted[i][j-1];
    }
  }

  return counted[x-1][y-1];
}



int main() {

  cout << "paths of 2x2: " << countPaths(2,2) << endl;
  cout << "paths of 3x3: " << countPaths(3,3) << endl;
  cout << "paths of 20x20: " << countPaths(20,20) << endl;

}
