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
            if (((ch >= 'A') && (ch <= 'Z')) || ch == 32)
                ciphertext_len++;
        }
        //printf("cipher text length: %d\n", ciphertext_len);

        char *newKey = (char*)malloc((ciphertext_len+1)*sizeof(char));
        char *decryptedMessage = (char*)malloc((ciphertext_len+1)*sizeof(char));

        //generating new key
        for (i = 0, j = 0; i < ciphertext_len; ++i, ++j)
        {
            if (j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }
        newKey[i] = '\0';
        printf("\nNew Generated Key: %s\n", newKey);

        rewind(f1);
        FILE *f2 = fopen("filedecrypt.txt", "w");
        ch = '0';
        for(i = 0; i < ciphertext_len && (ch = fgetc(f1)) != EOF; i++)
        {
            if(ch != 32) {decryptedMessage[i] = (((ch - newKey[i]) + 26) % 26) + 'A';}
            else {decryptedMessage[i] = ch;}
            fputc(decryptedMessage[i], f2);
        }
        decryptedMessage[i] = '\0';
        printf("\nActual Message: %s", decryptedMessage);
        fclose(f2);
        
    }
    fclose(f1);
}
