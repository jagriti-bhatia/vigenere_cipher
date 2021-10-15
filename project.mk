//makefile
$make -f Attester
gcc -c main.c file_encrypt.c file_decrypt.c encrypt.c decrypt.c explain.c header.h
gcc -o cipher main.o file_encrypt.o file_decrypt.o encrypt.o decrypt.o explain.o
$
