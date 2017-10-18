all:
	gcc -o pthread_create/pthread_create     pthread_create/pthread_create.c -lpthread
	gcc -o pthread_create/pthread_create_str pthread_create/pthread_create_arg.c -lpthread
	gcc -o pthread_create/pthread_create_int pthread_create/pthread_create_arg_int.c -lpthread

clean:
	rm -rf pthread_create/pthread_create
	rm -rf pthread_create/pthread_create_str
	rm -rf pthread_create/pthread_create_int
