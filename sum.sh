echo "Enter a positive Integer"
read n

if [ $n -le 0 ]
then
    echo "Not a Valid Input"
else
    result=`expr \( $n \* \( $n + 1 \) \) / 2`
    echo "sum of first $n natural numbers is: $result"
fi
