#!/bin/bash

if [ "$#" -gt 0 ]; then
  echo "The script doesn't take any parameter"
else
  i=0
  nb=0;

  while read x;
  do IFS=' ' read -r -a array <<< "$x";
    # IFS=' ' read -r -a array <<< "$x"
    # echo $array[1]
    if grep -s - "^martin" $array[1]; then
    #   if  sed 's/:/\n/g' <<< $x ; then
        nb=$((nb+1))
    #   fi
    fi
  done
  echo $nb
  # echo ${martin##*:}
  # grep "martin" -c -
fi
