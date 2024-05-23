echo "Enter a Decimal number"
read n
temp=$n
result=""
while [ $temp -gt 1 ]
do
    reminder=`expr $temp % 2`
    result="$reminder$result"
    temp=`expr $temp / 2`
done

echo "Decimal form of $n is 1$result"
