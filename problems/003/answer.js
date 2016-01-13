#!/usr/local/bin/node

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to list the prime factors of a number.
 */

var target = 600851475143;

 while (target % 2 == 0) {
     console.log("2 ");
     target /= 2;
 }

 for (var i = 3; i <= Math.sqrt(target); i += 2){
     while (target % i == 0){
   console.log(i + " ");
   target = target/i;
     }
 }

 if (target > 2) {
     console.log(target + " " );
 }
