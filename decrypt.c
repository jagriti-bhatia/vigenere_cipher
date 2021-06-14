#include <stdio.h>
#include <string.h>
void decryption(char ciphertext[], char key[])
{
    int ciphertext_len = strlen(ciphertext), keyLen = strlen(key), i, j;
    char newKey[ciphertext_len], decryptedMsg[ciphertext_len];

    //generating new key
    for(i = 0, j = 0; i < ciphertext_len; ++i, ++j)
    {
        if(j == keywLen)
            j = 0;

        newKey[i] = key[j];
    }
    newKey[i] = '\0';


    for(i = 0; i < ciphertext_len; ++i)
        decryptedMsg[i] = (((ciphertext[i] - newKey[i]) + 26) % 26) + 'A';
    decryptedMsg[i] = '\0';
 
    printf("\nNew Generated Key: %s", newKey);
    printf("\nDecrypted Message: %s", decryptedMsg);
 
}
