#!/bin/sh
#@author: Aplomb Huang
#@testing: my first script file



re1="\b[17]{5}\b$"

re5="\b[dD][a-zA-Z]*[dD]\b"

re6="\b[Aa][a-zA-Z]*\b"

re7="\b[0-9]+\b"

re8="([0-9]+[a-zA-Z]+[\d]*|[a-zA-Z]+[0-9]+[\w]*)"



count=0
count1=0
count2=0
count3=1
count4=0
count5=0
count6=0
count7=0
count8=0
temp=""
M_word=""
L_word=""
i=0


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

count4=$count1

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


