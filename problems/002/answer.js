#!/usr/local/bin/node

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to compute the sum of all even fib numbers
 */

var ret = 0;
var fib_a = 0;
var fib_b = 1;
var fib_c = 1;
var max = 4000000;
while (fib_c < max){
    fib_c = fib_a + fib_b;
    fib_a = fib_b;
    fib_b = fib_c;
    if ((fib_c % 2) == 0) ret += fib_c;
}

console.log("answer: " + ret);
