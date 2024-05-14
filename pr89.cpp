touch hello.txt
cat hello.txt
hi
how are you
touch hi.txt
cat h1.txt
cp hello.txt hi.txt
cat hi.txt
echo hello
touch factorial.sh
shx factorial.sh

# shell script for factorial of a number
# factorial using for loop

echo "Enter a number"

# Read the number
read num                     

fact=1                    

for((i=2;i<=num;i++))
{
  fact=$((fact * i)) 
}

echo $fact
