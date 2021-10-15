#include <stdio.h>
#include <string.h>
#include "header.h"

void file_encryption(char key[])
{
    FILE *f1 = fopen("plaintext.txt", "r");

    if (f1 == NULL)
        printf("error in opening the file");

    else
    {
        char ch;
        int keyLen = strlen(key), i, j;

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
