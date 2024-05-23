echo "Enter a Binary Number: "
read n
temp=$n
result=0
i=0
while [ $temp -gt 0 ]
do
    lastDigit=`expr $temp % 10`
    power=$((2**i))
    result=`expr $result + $power \* $lastDigit`
    temp=`expr $temp / 10`
    i=`expr $i + 1`
done
echo "Binary form of $n is $result"
