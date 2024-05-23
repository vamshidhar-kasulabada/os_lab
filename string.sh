echo "Enter a String"
read str
length=${#str}
i=0
while [ $i -le `expr $length / 2 - 1` ]
do
    firstChar=${str:$i:1}
    lastChar=${str:`expr $length - 1 - $i`:1}
    if [ $firstChar != $lastChar ]
    then
        echo "$str is not a palindrome"
        exit
    fi
    i=`expr $i + 1`
done

echo "$str is a palindrome"
