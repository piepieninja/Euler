#include <iostream>
#include <climits>

using namespace std;

/**
 * Author: Caleb Adams
 * Discription:
 */


int tri[15][15] = {
{75,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{95, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{17, 47, 82,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{18, 35, 87, 10,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{20, 04, 82, 47, 65,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{19, 01, 23, 75, 03, 34,  0,  0,  0,  0,  0,  0,  0,  0,  0},
{88, 02, 77, 73, 07, 63, 67,  0,  0,  0,  0,  0,  0,  0,  0},
{99, 65, 04, 28, 06, 16, 70, 92,  0,  0,  0,  0,  0,  0,  0},
{41, 41, 26, 56, 83, 40, 80, 70, 33,  0,  0,  0,  0,  0,  0},
{41, 48, 72, 33, 47, 32, 37, 16, 94, 29,  0,  0,  0,  0,  0},
{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,  0,  0,  0,  0},
{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,  0,  0,  0},
{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,  0,  0},
{63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,  0},
{04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
};

// greedy
// 95
// 47
// 87
// 82
// 75
// 73
// 28
// 83
// 47
// 43
// 73
// 91
// 67
// 98


int max(int x, int y){
	if (x > y) return x;
	else return y;
}

int main(){

	// make an array the same size:
	int sol[15][15];
	sol[0][0] = 0;

	// start with bottom row
	for (int i = 15; i > 0; i--){
		for (int j = 0; j < 16; j++){
			sol[i-1][j] = max(tri[i][j], tri[i][j+1]); //builds row of lower maximums to add
		}
		// add the maximums from before...
		for (int j = 0; j < 16; j++){
			tri[i-1][j] += sol[i-1][j];
		}
	}

	cout << "hopefully: ";
	cout << tri[0][0];

  return 0;
}
