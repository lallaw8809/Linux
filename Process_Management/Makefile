all:
	gcc -o create_new_process/fork  	create_new_process/fork.c
	gcc -o create_new_process/vfork 	create_new_process/vfork.c
	gcc -o create_new_process/clone 	create_new_process/clone_1.c
	gcc -o create_new_process/clone_parral  create_new_process/clone_2.c
	gcc -o daemon_process/daemon    	daemon_process/daemon.c
	gcc -o process_id/process_id   		process_id/process_id.c

clean:
	rm -rf create_new_process/fork	  create_new_process/vfork
	rm -rf create_new_process/clone   create_new_process/clone_parral
	rm -rf create_new_process/*~
	rm -rf daemon_process/daemon      daemon_process/daemon.txt
	rm -rf process_id/process_id
	rm -rf *~ 
