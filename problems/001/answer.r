#!/usr/bin/env Rscript

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
## 

x <- 0

for (i in 1:1000){
    if ((i %% 3) == 0 || (i %% 5) == 0){
       x <- x + i
    }
}

cat("answer: ", x)
cat("\n")