all:
	gcc -o pthread_create/pthread_create     pthread_create/pthread_create.c         -lpthread
	gcc -o pthread_create/pthread_create_str pthread_create/pthread_create_arg_str.c -lpthread
	gcc -o pthread_create/pthread_create_int pthread_create/pthread_create_arg_int.c -lpthread
	gcc -o multithread/multithread_create    multithread/multithread_create.c        -lpthread
	gcc -o multithread/multithread_run_md1   multithread/multithread_run_md1.c       -lpthread
	gcc -o multithread/multithread_run_md2   multithread/multithread_run_md2.c       -lpthread
	gcc -o mutex/method_1                    mutex/method_1.c                        -lpthread
	gcc -o mutex/method_2                    mutex/method_2.c                        -lpthread

clean:
	rm -rf pthread_create/pthread_create
	rm -rf pthread_create/pthread_create_str
	rm -rf pthread_create/pthread_create_int
	rm -rf multithread/multithread_create
	rm -rf multithread/multithread_run_md1
	rm -rf multithread/multithread_run_md2 
	rm -rf mutex/method_1
	rm -rf mutex/method_2
