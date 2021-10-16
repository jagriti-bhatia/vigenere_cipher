#include <stdio.h>
#include <string.h>
#include "header.h"

void file_decryption(char key[])
{
    //open the cipher text file
    FILE *f1 = fopen("cipher.txt", "r");

    //codition to check for error in opening the file
    if (f1 == NULL)
        printf("error in opening the file");

    else
    {
        char ch;
        int keyLen = strlen(key), i, j;

        //to find the length of the message in the file
        int ciphertext_len = 0;
        for ( i = 0; (ch = fgetc(f1)) != EOF; i++)
        {
            if (((ch >= 'A') && (ch <= 'Z'))||(ch >= 'a') && (ch <= 'z'))
                ciphertext_len++;
        }

   char ciphertext[ciphertext_len];
        char newKey[ciphertext_len];
      char  decrypted_msg[ciphertext_len];
        //generating new key
        for (  i=0, j = 0; i < ciphertext_len; ++i, ++j)
        {
            if (j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }
        newKey[i] = '\0';
        printf("\nNew Generated Key: %s\n", newKey);

//decryption
char c;

    for(i = 0; i < ciphertext_len; ++i)
    {
        while(( c=fgetc(f1)) !=EOF)
        {
        ciphertext[i]=c;
        }
    }
    for(i = 0; i < ciphertext_len; ++i)
    {        //to convert the cipher text to plain text character wise using the vigenere cipher formula
        decrypted_msg[i] = (((ciphertext[i] - newKey[i]) + 26) % 26) + 'A'; 
    }
    decrypted_msg[i] = '\0'; //denote the end of a string
    
    printf("\nDecrypted Message: %s", decrypted_msg);
 
       
    }


    fclose(f1);
}
