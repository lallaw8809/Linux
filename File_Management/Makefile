all:
	gcc -o bin/create    file_create.c
	gcc -o bin/read      file_read.c
	gcc -o bin/write     file_write.c
	gcc -o bin/append    file_append.c
	gcc -o bin/seek      lseek.c
	gcc -o bin/seek_set  lseek_set.c
	gcc -o bin/seek_cur  lseek_cur.c
	gcc -o bin/seek_end  lseek_end.c
	gcc -o bin/file_type file_type.c

clean:
	rm -rf *~
	rm -rf bin/*

