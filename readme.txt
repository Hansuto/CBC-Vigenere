Christopher Taliaferro - Ch119541
Security in Computing - CBC Vigenere 

***ENCRYPTION***

1) Run this command in eustis. 

   "gcc -o encipher V_encipher.c" (without quotes)

2) Run "encipher" followed by plaintext file name, keyword, and IV
   keep in mind that the keyword and IV MUST be the same length & lowercase. 
   
   "./encipher plaintext.txt cool bean" (without quotes)

3) The encryption program will write the ciphertext to a file named "ciphertext.txt".

***DECRYPTION***

1) Run this command in eustis. 

   "gcc -o decipher V_decipher.c" (without quotes)

2) Run "decipher" followed by ciphertext file name, keyword, and IV.
   Keep in mind that the keyword and IV MUST be the same length & lowercase &
   must be the same as the encryption program's. 
   
   "./decipher ciphertext.txt cool bean" (without quotes)

