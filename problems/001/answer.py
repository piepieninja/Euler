#!/usr/bin/env python

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
## 

a = 0

for i in range(1000):
    if (i % 3 == 0 or i % 5 == 0):
        a += i

print "answer: " + str(a)
