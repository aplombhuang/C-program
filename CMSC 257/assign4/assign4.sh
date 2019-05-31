#!/bin/sh
#@author: Aplomb Huang
#@V num#: 00800816
#@CMSC 257 Spring17 assignment 4
#@virsion: my first script file



re1="\b[17]{5}\b$"

#the following are regular expressions
   #re5 is regular expression of words begin and end with D/d
re5="\b[dD][a-zA-Z]*[dD]\b"  
   #re6 is for words begin with A/a
re6="\b[Aa][a-zA-Z]*\b"
   #re7 is for numeric words
re7="\b[0-9]+\b"
   #re8 is for alphanumeric words
re8="([0-9]+[a-zA-Z]+[\d]*|[a-zA-Z]+[0-9]+[\w]*)"


#these count variables are for the loops or word count later, delared here
count=0
count1=0
count2=0
count3=1
count4=0
count5=0
count6=0
count7=0
count8=0
#temp is for temperarily storing a word
temp=""
#M_word is for storing the most occurred word
M_word=""
#L_word is for storing the shortest word
L_word=""
i=0

#this loop is to take all the words in the file and stored in an array, also count the number of words and store in count1
filename="$1"
while read -r line
do
  words=${line}
  for word in $words
  do
     array[$i]="$word "
     i=$((i+1))
     count1=$((count1+1))
    
done
done < ${filename}

#this loop is to count words fitting regular expressions
filename="$1"
while read -r line
do
  words=${line}
  for word in $words
  do
    if [[ "$word" =~ $re1 ]]; then
     count=$((count+1))
    fi
    
    if [[ "$word" =~ $re5 ]]; then
     count5=$((count5+1))
    fi

    if [[ "$word" =~ $re6 ]]; then
     count6=$((count6+1))
    fi

    if [[ "$word" =~ $re7 ]]; then
     count7=$((count7+1))
    fi


     if [[ "$word" =~ $re8 ]]; then
	count8=$((count8+1))
     fi

done
done < ${filename}


echo "Total lines in file: " 
wc -l $1
echo "Total words in file:"
wc -w $1
#count4 stores the least occurred word's number, so preset the the greatest number of the words, which is the total number of words in the file
count4=$count1

#this loop finds the most and least occurred words by comparing all the words in the files one at a time 
for((i=0;i<$count1;i++))
do
   temp=${array[$i]}
   
    filename="$1"
    while read -r line
    do
    words=${line}
        for word in $words
        do
        
	if [ "$word" = $temp ]; then
          count2=$((count2+1))
        fi

        done
    done < ${filename}   
  
    if [[ "$count3" < "$count2" ]]; then
    count3=$count2
    M_word=$temp
    fi

    if [[ "$count4" > "$count2" ]]; then
    count4=$count2
    L_word=$temp
    fi
    
    count2=0

done

echo "Most words: $M_word  counts: $count3"

echo "Least words: $L_word  counts $count4"

echo "There are $count5 words begin and end with D/d: "

filename="$1"
while read -r line
do
  words=${line}
  for word in $words
  do
    
    if [[ "$word" =~ $re5 ]]; then
     echo "$word "
    fi

done
done < ${filename}

echo "There are $count6 words begin with A/a: "

filename="$1"
while read -r line
do
  words=${line}
  for word in $words
  do
    
    if [[ "$word" =~ $re6 ]]; then
     echo "$word "
    fi

done
done < ${filename}

echo "Numeric word count: $count7"
echo "Alpha-Numeric word count: $count8"


