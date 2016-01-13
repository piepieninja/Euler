#!/usr/bin/env ruby

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to list the prime factors of a number.
##

include Math

largenum = 600851475143

while (largenum % 2 == 0)
    print 2
    print " "
    largenum /= 2;
end

i = 3
while (i <= Math.sqrt(largenum))
    while (largenum % i == 0)
        print i
        print " "
        largenum = largenum/i
    end
    i += 2
end

if (largenum > 2)
    print largenum
    print " \n"
end
