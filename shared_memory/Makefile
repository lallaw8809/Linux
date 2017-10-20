all:
	gcc shm.c            -o shm
	gcc shm_ipc/server.c -o shm_ipc/server
	gcc shm_ipc/client.c -o shm_ipc/client

clean:
	rm -rf *~ shm
	rm -rf shm_ipc/*~ shm_ipc/server shm_ipc/client
