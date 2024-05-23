echo "Enter First Number: "
read a
echo "Enter Second Number: "
read b
echo "Enter Third Number: "
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
    echo "$a is greater"
elif [ $b -gt $a ] && [ $b -gt $c ]
then
    echo "$b is greater"
else
    echo "$c is greater"
fi

