echo "Enter a positive Integer: "
read n
if [ $n -le 0 ]
then
    echo "Not a Valid Input"
else
    digits=0
    temp=$n
    while [ $temp -gt 0 ]
    do
        temp=`expr $temp / 10`
        digits=`expr $digits + 1`
    done

    result=0
    temp=$n
    while [ $temp -gt 0 ]
    do
        lastDigit=`expr $temp % 10`
        result=$((result+$((lastDigit**digits))))
        temp=`expr $temp / 10`
    done
    if [ $n -eq $result ]
    then
        echo "$n is an armstrong number"
    else
        echo "$n is not an armstrong number"
    fi
fi
