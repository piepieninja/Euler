
##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to compute the sum of all the multiples
# of 3 or 5 below int i.
## 

N=0
I=0

while [ $I -lt 1000 ]
do
    if [ $((I % 3)) -eq 0 -o $((I % 5)) -eq 0 ]
    then
       N=$((N + I))
    fi
    I=$((I + 1))
done
echo "answer: $N"
