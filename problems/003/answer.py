#!/usr/bin/env python

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to list the prime factors of a number.
##

import math

largenum = 600851475143

while (largenum % 2 == 0):
    print 2
    largenum /= 2;

i = 3
while (i <= math.sqrt(largenum)):
    while (largenum % i == 0):
        print i
        largenum = largenum/i
    i += 2

if (largenum > 2):
    print largenum
