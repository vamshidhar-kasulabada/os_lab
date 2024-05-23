echo "Enter Starting Range: " 
read a
echo "Enter Ending Range: "
read b
echo "Prime Numbers between $a and $b are: "
i=$a
while [ $i -le $b ]
do
    j=2
    isPrime=1
    while [ $j -le `expr $i / 2` ]
    do
        if [ `expr $i % $j` -eq 0 ]
        then
            isPrime=0
            break 
        fi
        j=`expr $j + 1`
    done
    if [ $i -gt 1 ] && [ $isPrime -eq 1 ]
    then
        echo "$i"
    fi
    i=`expr $i + 1`
done
