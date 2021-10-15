a.out: main.o encrypt.o decrypt.o  explain.o 
    gcc main.o encrypt.o decrypt.o explain.o 

main.o : main.c header.h 
    gcc -c main.c 

encrypt.o:encrypt.c header.h
    gcc -c encrypt.c

decrypt.o: decrypt.c header.h
    gcc -c decrypt.c
	
explain.o: explain.c header.h
    gcc -c explain.c
