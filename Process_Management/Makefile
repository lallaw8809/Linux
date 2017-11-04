all:
	gcc -o create_new_process/fork  	create_new_process/fork.c
	gcc -o create_new_process/vfork 	create_new_process/vfork.c
	gcc -o create_new_process/clone 	create_new_process/clone_1.c
	gcc -o create_new_process/clone_parral  create_new_process/clone_2.c
	gcc -o daemon_process/daemon    	daemon_process/daemon.c
	gcc -o process_id/process_id   		process_id/process_id.c
	gcc -o wait/wait	   		wait/wait.c
	gcc -o wait/zombie	   		wait/zombie.c
	gcc -o exe_family/execl                 exe_family/execl.c
	gcc -o exe_family/execle                exe_family/execle.c
	gcc -o exe_family/execlp                exe_family/execlp.c
	gcc -o exe_family/execv                 exe_family/execv.c
	gcc -o exe_family/execvp                exe_family/execvp.c
	gcc -o exe_family/execvpe               exe_family/execvpe.c
	gcc -o exe_family/exe_family            exe_family/exec_family.c

clean:
	rm -rf create_new_process/fork	  create_new_process/vfork
	rm -rf create_new_process/clone   create_new_process/clone_parral
	rm -rf create_new_process/*~
	rm -rf daemon_process/daemon      daemon_process/daemon.txt
	rm -rf process_id/process_id
	rm -rf wait/wait  wait/*~	  wait/zombie
	rm -rf exe_family/execl  	  exe_family/execle  exe_family/execlp
	rm -rf exe_family/execv  	  exe_family/execvp  exe_family/execvpe
	rm -rf exe_family/exe_family exe_family/*~
	rm -rf *~
