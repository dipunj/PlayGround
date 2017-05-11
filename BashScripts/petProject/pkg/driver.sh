#! /bin/bash
# $1 - executable 
# $2 input file
# $3 output file

# to make sure that the file $3 doesn't exist
rm $3

while read STRING;
do
	echo $STRING | $1 >> $3
done < $2

sort $3 > temp
uniq temp > $3
rm temp
