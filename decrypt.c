#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//parameters for the cipher text and the keyword
void decryption(char ciphertext[], char key[]) 
{
    int ciphertext_len = strlen(ciphertext); //length of ciphertext
    int key_len = strlen(key); //length of key
    int i, j; //integers to run for loop

    //defining array for the decrypted message and the key generated
    char *new_key = (char*)malloc((ciphertext_len+1)*sizeof(char));
    char *decrypted_msg = (char*)malloc((ciphertext_len+1)*sizeof(char));

    //generating new key
    for(i = 0, j = 0; i < ciphertext_len; ++i, ++j) 
    {
        //to repeat characters from start when the length of the ciphertext is > that of the keyword
        if(j == key_len) 
            j = 0;

        //to generate a new key from the given keyword such that the length of newkey = length of ciphertext
        new_key[i] = key[j]; 
    }
    new_key[i] = '\0'; //denote the end of a string

    //decryption
    for(i = 0; i < ciphertext_len; ++i)
        //to convert the cipher text to plain text character wise using the vigenere cipher formula
        decrypted_msg[i] = (((ciphertext[i] - new_key[i]) + 26) % 26) + 'A'; 
    decrypted_msg[i] = '\0'; //denote the end of a string

    printf("\nNew Generated Key: %s", new_key);
    printf("\nDecrypted Message: %s", decrypted_msg);
}
