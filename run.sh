#!/bin/sh
## run.sh for  in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/PSU_2015_lemipc
## 
## Made by 
## Login   <@epitech.net>
## 
## Started on  Wed Mar 23 03:21:34 2016 
## Last update Wed Mar 23 21:00:05 2016 
##

cmpt=0
div=`expr $1 / $2`
team=1

while [ $cmpt -lt $1 ] ; do
    ./lemipc $PWD $team &
    cmpt=$(($cmpt+1))
    if [ `echo "$cmpt % $div" | bc` -eq 0 ]
    then
	team=$(($team+1))
    fi
done
