#! bin/bash

echo "Enter the characters"
read var
echo $var > input.txt
echo "The chars entered are $var"

echo "Enter the size of the word"
read size

# remove pre-existing files / fail-safe
rm power.out permute.out trim.out temp

# compilation
gcc powerset.c -lm -D SIZE=$size -o power.out
gcc permuteStrings.c -o permute.out
gcc trimDict.c -D TRIM=$size -o trim.out

# run the driver
sh driver.sh ./power.out input.txt intermed.txt
sh driver.sh ./permute.out intermed.txt output.txt

# costly operation - trimming dictionary
echo "Preprocessing :: It can take a while...."
sh driver.sh ./trim.out /usr/share/dict/american-english temp
echo "Preprocessing :: done"

sort temp > dict_trimmed.txt
sort output.txt > temp
cp temp output.txt

# common lines are written to answer.txt
comm -12 dict_trimmed.txt output.txt > ../answer.txt
less ../answer.txt
echo "You can find this file in parent of pwd"
