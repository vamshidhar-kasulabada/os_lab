echo "Enter a positive Integer: "
read n
if [ $n -le 0 ]
then
    echo "Not a Valid input"
elif [ $n -eq 1 ]
then
    echo "1 is neither prime nor composite"
else
    i=2
    while [ $i -le `expr $n / 2` ]
    do
        if [ `expr $n % $i` -eq 0 ]
        then
            echo "$n is not a prime number"
            exit
        fi
        i=`expr $i + 1`
    done
        echo "$n is a prime number"
fi
