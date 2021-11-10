compile:
	g++ server.cpp -o server -std=c++11 -lpthread
	g++ client.cpp -o client
	g++ gen_transactions_file.cpp -o gentransc -std=c++11 
	g++ gen_transactions_file_w_rate.cpp -o gen_transactions_file_w_rate -std=c++11 

server:
	g++ server.cpp -o server -std=c++11 -lpthread

client:
	g++ client.cpp -o client

gentransc:
	g++ gen_transactions_file.cpp -o gentransc -std=c++11 

gentransc_rate:
	g++ gen_transactions_file_w_rate.cpp -o gen_transactions_file_w_rate -std=c++11 

clean:
	rm server client gentransc gen_transactions_file_w_rate