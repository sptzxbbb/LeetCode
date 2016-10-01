#!/bin/bash

i=0
cat file.txt | while read line
do
    i=`expr $i + 1`
    if [ $i == 10 ];then
        echo $line
    fi
done
