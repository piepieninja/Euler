
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
