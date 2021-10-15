#include <stdio.h>
#include <string.h>

//parameters for the cipher text and the keyword
void decryption(char ciphertext[], char key[]) 
{
    int ciphertext_len = strlen(ciphertext); //length of ciphertext
    int key_len = strlen(key); //length of key
    int i, j; //integers to run for loop

    //defining array for the decrypted message and the key generated
    char new_key[ciphertext_len], decrypted_msg[ciphertext_len]; 

    //generating new key
    for(i = 0, j = 0; i < ciphertext_len; ++i, ++j) 
    {
        if (ciphertext[i]==' ') //wherever a space occurs in the text, it should occur in the newkey
        {
            new_key[i]=' ';
            j--; //making sure letters of the key aren't missed
        }

        //to repeat characters from start when the length of the ciphertext is > that of the keyword
        if(j == key_len) 
            j = 0;

        //to generate a new key from the given keyword such that the length of newkey = length of ciphertext
        new_key[i] = key[j]; 
    }
    new_key[i] = '\0'; //denote the end of a string

    //decryption
    for(i = 0; i < ciphertext_len; ++i)
    {
        if (ciphertext[i]==' ') //wherever a space occurs in the text, it should occur in the decryptedmsg
            decrypted_msg[i]=' ';
        //to convert the cipher text to plain text character wise using the vigenere cipher formula
        else
            decrypted_msg[i] = (((ciphertext[i] - new_key[i]) + 26) % 26) + 'A'; 
    }
    decrypted_msg[i] = '\0'; //denote the end of a string

    printf("\nNew Generated Key: %s", new_key);
    printf("\nDecrypted Message: %s", decrypted_msg);
}

/* //DEMO
int main()
{
    decryption("ZI CVT WQNGRZGVTW AVZH CQYGLMGJ", "DECEPTIVE");
}
*/
