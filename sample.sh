echo "Enter two numbers: " 
read b a
while [[ b -ne 0 ]];
do
	r=$((a%b))
	a=$b
	b=$r
done
echo "The gcd is : " $a
