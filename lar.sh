read -p "Enter 3 numbers " a b c
if (($a > $b && $a > $c));
then
	echo $a "is greatest "
elif (($b>$a && $b>$c));
then
	echo $b "is greatest"
else
	echo $c "is greatest"
fi


