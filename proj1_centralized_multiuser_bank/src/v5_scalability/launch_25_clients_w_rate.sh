#!/bin/bash


rate=0.1 # input 0.1, 1, 5, 10, 50, 100, 200  milliseconds

echo "" > "avg_transaction_complt_time_log.txt" # clean file

./gen_transactions_file_w_rate $rate

k=25 # launch 25 clients
for ((i = 1; i <= $k; i++))
do
	./client $rate &
done

exit(0)
