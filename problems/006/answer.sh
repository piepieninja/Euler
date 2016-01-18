
##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
## 

echo "====================== BASH/SHELL ======================"

result_1=0
low_1=0
high_1=100
while [ $low_1 -lt $high_1 ]; do
    low_1=$((low_1 + 1))
    sqr_1=$((low_1 * low_1))
    result_1=$((result_1 + sqr_1))
done

echo "sum of squares: ${result_1}" 

result_2=0
low_2=0
high_2=100
while [ $low_2 -lt $high_2 ]; do
    low_2=$((low_2 + 1))
    result_2=$((result_2 + low_2))
done
result_2=$((result_2 * result_2))

echo "square of sums: ${result_2}"

result=$((result_2 - result_1))

echo "result: ${result}"

