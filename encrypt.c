#include<stdio.h>
#include<string.h>

//parameters for the plaintext and the keyword
void encryption(char text[],char key[])
{
    int textlen = strlen(text), keylen = strlen(key), i, j;
    //defining array for encrypted message and key generated
    char newkey[textlen], encryptedmsg[textlen];

    //generating new key
    for(i = 0, j = 0; i < textlen; ++i, ++j)
	  {
          //to repeat characters from start when the length of the ciphertext is > that of the keyword
        if(j == keylen)
            j = 0;

        //to generate a new key from the given keyword such that the length of newkey = length of ciphertext
        newkey[i] = key[j];
    }
    newkey[i] = '\0'; //denote the end of a string

     
     for(i = 0; i < textlen; ++i)
     //to convert the plain text to cipher text character wise using the vigenere cipher formula
         encryptedmsg[i] = ((text[i] + newkey[i]) % 26) + 'A';
     encryptedmsg[i] = '\0'; //denote the end of the string

	 printf("\nNew Generated Key: %s", newkey);
   printf("\nEncrypted Message: %s", encryptedmsg);
}
