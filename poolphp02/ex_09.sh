#!/bin/bash

if [ "$#" -gt 0 ]; then
  echo "The script doesn't take any parameter"
else
  line1=${MY_LINE1}
  line2=${MY_LINE2}
  count=0

  while read x;
  do i=$((i+1));
    if [ $((i%2)) -eq 0 ] && [ $i -ge $line1 ] && [ $i -le $line2 ]; then
      IFS=';'
      read -a strarr <<< "$x"

      for val in "${strarr[@]}";
      do echo -n $val | rev;
        count=$((count+1))
        if [ $(($(($line2-$line1))/2)) -ge $count ]; then
          echo -n ', '
        else
          echo -n '.'
        fi
        # echo "Je suis le nombre ${count}"
        break
      done
    fi
  done
fi
