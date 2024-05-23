echo "Enter a: "
read a
echo "Enter b: "
read b
echo "
1.Addition
2.Subtraction
3.Multiplication
4.Division"
echo "Enter Arithmetic Operation: "
read op

case $op in
    1) echo `expr $a + $b`;;
    2) echo `expr $a - $b`;;
    3) echo `expr $a \* $b`;;
    4) echo `expr $a / $b`;;
    *) echo "Not a Valid Input";;
esac
