all:
	gcc -o File/create    		File/file_create.c
	gcc -o File/read      		File/file_read.c
	gcc -o File/write     		File/file_write.c
	gcc -o File/append    		File/file_append.c
	gcc -o Seek/seek      		Seek/lseek.c
	gcc -o Seek/seek_set  		Seek/lseek_set.c
	gcc -o Seek/seek_cur  		Seek/lseek_cur.c
	gcc -o Seek/seek_end  		Seek/lseek_end.c
	gcc -o Stat/fstat     		Stat/fstat.c
	gcc -o Stat/lstat     		Stat/lstat.c
	gcc -o Stat/stat      		Stat/stat.c
	gcc -o Dup/dup			Dup/dup.c
	gcc -o Dup/dup2			Dup/dup2.c
	gcc -o Dup/dup3			Dup/dup3.c
	gcc -o File_type/file_type	File_type/file_type.c
	gcc -o File_type/file_type_creat  File_type/file_create_type.c

clean:
	rm -rf File/*~      File/create     File/read     File/write     File/append
	rm -rf Seek/*~      Seek/seek       Seek/seek_set Seek/seek_cur  Seek/seek_end
	rm -rf Stat/stat    Stat/lstat	    Stat/fstat
	rm -rf Dup/*~       Dup/dup         Dup/dup2      Dup/dup3       Dup/*.txt
	rm -rf File_type/*~ File_type/file_type  File_type/file_type_creat
	rm -rf *~ File/*.txt File_type/*.txt
