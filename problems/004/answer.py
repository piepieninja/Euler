#!/usr/bin/env python

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
##

import math

def isPallandrome (x):
    reverse = 0
    n = x
    while (n != 0):
        reverse = reverse * 10
        reverse = reverse +n%10
        n = n/10
    if (x == reverse):        
        return 1
    else:
        return 0

max_pall = 0;
for i in range(999):
    for j in range(999):
        if (isPallandrome(i * j) and (i * j > max_pall)):
            max_pall = i * j
            print "Largest Pallandrome is i=" + str(i) + ", j=" + str(j) + " :=: " + str(max_pall) 

