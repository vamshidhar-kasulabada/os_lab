echo "Enter a positive Integer: "
read n
if [ $n -le 0 ]
then
    echo "Not a valid Input"
else
    result=0
    i=1
    while [ $i -lt $n ]
    do
        if [ `expr $n % $i` -eq 0 ]
        then
            result=`expr $result + $i`
        fi
        i=`expr $i + 1`
    done
    if [ $n -eq $result ]
    then
        echo "$n is a perfect number"
    else
        echo "$n is not a perfect number"
    fi
fi
