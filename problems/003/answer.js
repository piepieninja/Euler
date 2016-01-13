#!/usr/local/bin/node

/**
 * Author: Caleb Adams
 * Discription: This is a very simple algorithm that runs in
 * linear time O(n) to list the prime factors of a number.
 */

var target = 600851475143;
 
 while (target % 2 == 0) {
     System.out.print("2 ");
     target /= 2;
 }

 for (int i = 3; i <= Math.sqrt(target); i += 2){
     while (target % i == 0){
   System.out.print(i + " ");
   target = target/i;
     }
 }

 if (target > 2) {
     System.out.print(Long.toUnsignedString(target) + " " );
 }
