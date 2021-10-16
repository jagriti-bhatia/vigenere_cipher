#include <stdio.h>
#include <stdlib.h>
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
            if (((ch >= 'A') && (ch <= 'Z')) || ch == 32)
                ciphertext_len++;
        }
        //printf("cipher text length: %d\n", ciphertext_len);

        char *newKey = (char*)malloc((ciphertext_len+1)*sizeof(char));
        char *encryptedMessage = (char*)malloc((ciphertext_len+1)*sizeof(char));

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
        FILE *f2 = fopen("fileencrypt.txt", "w");
        ch = '0';
        for(i = 0; i < ciphertext_len && (ch = fgetc(f1)) != EOF; i++)
        {
            if(ch != 32) {encryptedMessage[i] = ((ch + newKey[i]) % 26) + 'A';}
            else {encryptedMessage[i] = ch;}
            fputc(encryptedMessage[i], f2);
        }
        encryptedMessage[i] = '\0';
        printf("\nEncrypted Message: %s", encryptedMessage);
        fclose(f2);
    }
    fclose(f1);
}
