// Christopher Taliaferro - Ch119541
// Security in Computing :: Vigenere CBC

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 9999

char a2d(char a);

int main(int argc, char **argv)
{
    int i = 0, cLength, blockSize, temp;
    char cipher[MAX_LENGTH], buffer,
          *keyword, *iv;

		// Checks # of Program arguments
    if (argc < 3) return 1;

    // Initialize Variables
    keyword = calloc(strlen(argv[2]), sizeof(char));
    iv = calloc(strlen(argv[3]), sizeof(char));
    strcpy(keyword, argv[2]);
    strcpy(iv, argv[3]);
    blockSize = strlen(keyword);

    printf("\nCBC Vigenere Decrypt\n");
    printf("Ciphertext file name : %s\n", argv[1]);
    printf("Keyword : %s\n", keyword);
    printf("IV : %s\n\n", iv);
    printf("Ciphertext : ");

    FILE * fin;

    if ((fin = fopen(argv[1], "r")) == NULL) return 1;

		// Print Ciphertext
    while (fscanf(fin, "%c", &buffer) != EOF)
        printf("%c", cipher[i++] = buffer);

    cLength = i;

    printf("\n\nPlaintext : ");

    // CBC Vigenere Decrypt
    for(i = 0; i < cLength; i++)
      if (i < blockSize)
      {
        temp = a2d(cipher[i]) - a2d(iv[i]) - a2d(keyword[i % blockSize]);
        while (temp < 0) temp += 26;
        printf("%c", temp + 'a');
      }
      else
      {
        temp = a2d(cipher[i]) - a2d(cipher[i - blockSize]) - a2d(keyword[i % blockSize]);
        while (temp < 0) temp += 26;
        printf("%c", temp + 'a');
      }

    printf("\n\nNumber of characters in ciphertext : %d\n",cLength);
    printf("Blocksize : (%d)\n\n", blockSize);

    fclose(fin);
    free(keyword);
    free(iv);

    return 0;
}

// Converts ASCII into base 26
char a2d(char a)
{
 return a - 'a';
}
