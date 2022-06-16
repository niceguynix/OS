echo enter the filename
read text
c=`echo $text | wc -c`
c=`expr $c - 1`
w=`echo $text | wc -w`
echo no of characters: $c
echo no of words: $w