
all:server_client/sem_server.c server_client/sem_client.c server_client/common.h
	gcc -o server_client/server server_client/sem_server.c
	gcc -o server_client/client server_client/sem_client.c
	gcc -o sem_demo semaphore.c

clean:
	rm -rf server_client/server server_client/client
	rm -rf server_client/*~ *~ sem_demo

