/*
main - done
encrypt - done
decrypt - done
explain - done
header - done
makefile - figure out how to write
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <conio.h>

int main()
{
  int choice;

  printf("Welcome to Vigenere Cipher");

  do
  {
    printf("\n\nEnter your choice: \n");
    printf("1 - What is Vigenere Cipher (Help menu) \n");
    printf("2 - Encryption \n");
    printf("3 - Decryption \n");
    printf("4 - File Encryption \n");
    printf("5 - File Decryption \n");
    printf("6 - Exit \n");

    scanf("%d", &choice);

    char plaintext[50], key[50], encrypt[50];

    switch (choice)
    {
    case 1:
      explain();
      break;

    case 2:
      printf("Enter the plaintext (text to be encrypted) \n");
      gets(plaintext);
      printf("Enter the key \n");
      gets(key);

      strupr(plaintext);
      strupr(key);
      encryption(plaintext, key);
      break;

    case 3:
      printf("Enter the encrypted text \n");
      gets(encrypt);
      printf("Enter the key\n");
      gets(key);
      strupr(encrypt);
      strupr(key);
      decryption(encrypt, key);
      break;

    case 4:
      printf("Enter the key to encrypt the file\n");
      gets(key);
      file_encryption(key);
      break;

    case 5:
      printf("Enter the key to decrypt the file\n");
      gets(key);
      file_decryption(key);
      break;

    case 6:
      exit(0);

    default:
      printf("Invalid Output. Please try again. \n");
      break;
    }

  } while (choice != 6);

  return 0;
}
