#!/bin/bash

if [ "$#" -gt 0 ]; then
  echo "The script doesn't take any parameter"
else
  i=0

  while read x;
  do i=$((i+1));
    if [ $((i%2)) -eq 0 ]; then
      echo $x
    fi
  done
fi
