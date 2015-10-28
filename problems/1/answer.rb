#!/usr/bin/env ruby

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
##

a = 0
i = 0
while i < 10000
     if (i % 3 == 0 or i % 5 == 0)
         a += i
     end
     i += 1
end

puts "answer: " + a.to_s
