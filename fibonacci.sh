echo "Enter a positive Integer: "
read n
if [ $n -le 0 ]
then
    echo "Not a Valid Input"
else
    echo "First $n fibonacci numbers are: "
    a=0
    b=1
    i=1
    while [ $i -le $n ]
    do
        echo $a
        c=`expr $a + $b`
        a=$b
        b=$c
        i=`expr $i + 1`
    done
fi

