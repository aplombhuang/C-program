#!/usr/bin/env bash

#regular expression to find the word made up of 1 or 7 of length 5
re1="\b[17]{5}\b$"

count=0

filename="$1"
while read -r line
do
   words=${line}
   for word in $words
   do 
	if [[ $word =~ $re1 ]]; then
	    echo ' matching word: '$word
	    count=$((count+1))
	fi
   done 
done < ${filename}

echo "matching count: $count"

