all:
	g++ client.cpp -o app_client -L/usr/local/lib -lzmq
	g++ server.cpp -o app_server -L/usr/local/lib -lzmq
client:
	./app_client
server:
	./app_server
clean:
	rm app_client
	rm app_server
