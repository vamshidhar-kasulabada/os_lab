echo "Enter a Whole Number: "
read input
if [ $input -lt 0 ]
then
    echo "Not a Valid Input"
else
    n=$input
    result=1
    while [ $n -gt 1 ]
    do
        result=`expr $result \* $n`
        n=`expr $n - 1`
    done
    echo "Factorial of $input is $result"
fi
