printf("Enter the plaintext (text to be encrypted) \n");
      scanf("%s", plaintext);
      printf("Enter the key \n");
      scanf("%s", key);
      strupr(plaintext);
      strupr(key);
      encryption(plaintext, key);