#!/bin/bash

if [ "$#" -gt 1 ]; then
    echo "The number of argument should be less than 2"
elif [ "$#" -eq 1 ]; then
  grep -ci $1
else
  i=0

  while read x;
  do i=$((i+1));
  done
  echo $i
fi
