#!/usr/local/bin/node

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to compute the sum of all the multiples 
 * of 3 or 5 below int i.
 */

var n= 0;

for (var i = 0; i < 1000; i++){
    if (i % 3 == 0 || i % 5 == 0){
	n += i;
    }
}

console.log("answer: " + n);
