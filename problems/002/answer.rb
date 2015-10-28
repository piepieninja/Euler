#!/usr/bin/env ruby

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all even fib numebrs
##

ret = 0
fib_a = 0
fib_b = 1
fib_c = 1
max = 4000000
while fib_c < max
  fib_c = fib_a + fib_b
  fib_a = fib_b
  fib_b = fib_c
  if fib_c % 2 == 0
      ret += fib_c
  end
end

puts "answer: " + ret.to_s
    
