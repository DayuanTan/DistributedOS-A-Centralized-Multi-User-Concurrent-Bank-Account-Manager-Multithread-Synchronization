#!/bin/bash
k=$1
for ((i = 1; i <= $k; i++))
do
	./client &
done
exit(0)
