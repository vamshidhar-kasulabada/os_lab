echo "Enter a positive Integer: "
read n
if [ $n -lt 0 ]
then
    echo "Not a Valid Input"
else
    result=0
    temp=$n
    while [ $temp -gt 0 ]
    do
        lastDigit=`expr $temp % 10`
        result=`expr $result \* 10 + $lastDigit`
        temp=`expr $temp / 10`
    done
    if [ $result -eq $n ]
    then
        echo "$n is a palindrome"
    else
        echo "$n is not a palindrome"
    fi
fi

