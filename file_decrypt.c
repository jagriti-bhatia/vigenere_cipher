#include <stdio.h>
#include <stdlib.h>
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
        for (int i = 0; (ch = fgetc(f1)) != EOF; i++)
        {
            if ((ch >= 'A') && (ch <= 'Z'))
                ciphertext_len++;
        }
        //printf("cipher text length: %d\n", ciphertext_len);

        char *newKey = (char*)malloc((ciphertext_len+1)*sizeof(char));

        //generating new key
        for (i = 0, j = 0; i < ciphertext_len; ++i, ++j)
        {
            if (j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }
        newKey[i] = '\0';
        printf("\nNew Generated Key: %s\n", newKey);

        
        
    }
    fclose(f1);
}
