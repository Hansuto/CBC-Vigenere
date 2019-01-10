// Christopher Taliaferro - Ch119541
// Security in Computing :: Vigenere CBC

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char a2d(char a);

int main(int argc, char **argv)
{
    int i = 0, pLength, blockSize, pad = 0;
    char plain[9999], cipher[9999], buffer,
          *keyword, *iv;

    // Checks # of Program arguments
    if (argc < 3) return 1;

    // Initialize Variables
    keyword = calloc(strlen(argv[2]), sizeof(char));
    iv = calloc(strlen(argv[3]), sizeof(char));
    strcpy(keyword, argv[2]);
    strcpy(iv, argv[3]);
    blockSize = strlen(keyword);

    // Header
    printf("\nCBC Vigenere Encrypt\n");
    printf("Plaintext file name : %s\n", argv[1]);
    printf("Keyword : %s\n",keyword);
    printf("IV : %s\n\n",iv);
    printf("Plaintext : ");

    FILE * fin;
    FILE * fout;

    if ((fin = fopen(argv[1], "r")) == NULL) return 1;
    if ((fout = fopen("ciphertext.txt", "w")) == NULL) return 1;

    // Parse input file
    while (fscanf(fin, "%c", &buffer) != EOF)
      if (tolower(buffer) >= 'a' && tolower(buffer) <= 'z')
        printf("%c", plain[i++] = tolower(buffer));

    // Captures length without padding
    pLength = i;

    // Padding with 'x'
    while (((i+pad) % blockSize) != 0)
      plain[i + pad++] = 'x';

    printf("\n\nCiphertext : ");

    // CBC Vigenere Encrypt
    for(i = 0; i < (pLength+ pad); i++)
    {
      if (i < blockSize)
      {
        cipher[i] = (((a2d(keyword[i % blockSize]) + a2d(plain[i]) + a2d(iv[i])) % 26) + 'a');
        printf("%c", cipher[i]);
        fputc(cipher[i], fout);
      }
      else
      {
        cipher[i] = (((a2d(keyword[i % blockSize]) + a2d(plain[i]) + a2d(cipher[i - blockSize])) % 26) + 'a');
        printf("%c", cipher[i]);
        fputc(cipher[i], fout);
      }
    }

    printf("\n\nNumber of characters in plaintext : %d\n",pLength);
    printf("Blocksize : (%d)\n", blockSize);
    printf("Pad added : %d\n",pad);
    printf("Cipher text filename : ciphertext.txt\n\n");

    fclose(fin);
    fclose(fout);
    free(keyword);
    free(iv);

    return 0;
}

// Converts ASCII into base 26
char a2d(char a)
{
 return a - 'a';
}
