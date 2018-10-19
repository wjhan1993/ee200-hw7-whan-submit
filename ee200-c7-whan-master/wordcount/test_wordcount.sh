#! /bin/bash

# Put whatever tests you want here, e.g., 
echo "words, words, words"| ./wordcount
echo "words, words, words"| ./wordcount -l
echo "words, words, words"| ./wordcount -w
echo "words, words, words"| ./wordcount -c
./wordcount test.txt
