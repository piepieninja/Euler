#!/usr/bin/env Rscript

x <- 0

for (i in 1:1000){
    if ((i %% 3) == 0 || (i %% 5) == 0){
       x <- x + i
    }
}

cat("answer: ", x)
cat("\n")