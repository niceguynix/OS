echo " enter the total number of values "
read n
echo " enter the value "
for ((i=0;i<n;i++))
do
read a[$i]
done
for ((i=0;i<n;i++))
do
for ((j=i+1;j<n;j++))
do
if [ ${a[$i]} -gt ${a[$j]} ]
then
x=${a[$i]}
a[$i]=${a[$j]}
a[$j]=$x
fi
done
done
echo " ascending order is "
for ((i=0;i<n;i++))
do
echo " ${a[$i]} "
done