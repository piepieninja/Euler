# This is it

##
# Author: Caleb Adams
# Discription: This is a very simple algorithm that runs in
# linear time O(n) to list the prime factors of a number.
##

target=600851475143
i=3

while [ $((target % 2)) -eq 0 ]; do
  echo "2 "
  target=$((target/2))
done

sqrt=$(echo "sqrt ( $target )" | bc -l)
loopnum=$(echo "$i<$sqrt" | bc)

while [[ $loopnum -eq 1 ]]; do
  sqrt=$(echo "sqrt ( $target )" | bc -l)
  loopnum=$(echo "$i<$sqrt" | bc)
  while [[ $((target % i)) -eq 0 ]]; do
    echo "$i "
    target=$((target / i))
  done
  i=$((i + 2))
done

if [ $target -gt 2 ]
then
echo "$target "
fi
