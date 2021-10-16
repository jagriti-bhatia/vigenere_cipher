//makefile
a.exe : decrypt.o encrypt.o explain.o file_decrypt.o file_encrypt.o main.o
	gcc decrypt.o encrypt.o explain.o file_decrypt.o file_encrypt.o main.o
main.o:	main.c header.h
	gcc -c main.c
encrypt.o:	encrypt.c header.h
	gcc -c encrypt.c
decrypt.o:	decrypt.c header.h
	gcc -c decrypt.c
explain.o:	explain.c header.h
	gcc -c explain.c
file_decrypt.o:	file_decrypt.c header.h
	gcc -c file_decrypt.c
file_encrypt.o:	file_encrypt.c header.h
	gcc -c file_encrypt.c