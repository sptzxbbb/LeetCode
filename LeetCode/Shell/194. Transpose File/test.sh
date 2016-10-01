#!/bin/bash

awk '
    {
        for(i=1; i<=NF; i++) {
            if(NR == 1) {
                line[i] = $i
            } else {
                line[i] = line[i]" "$i
            }
        }
    }
    END {
         for(i=1; i<=NF; i++) {
             print line[i]
         }
       }
    ' file.txt
