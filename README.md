# EncryptDecrypt
Encryption and Decryption of a file in C

INPUT:

When running the program, it will ask the user to input whether they want to encrypt or decrypt the file. For encrypting, the user should input either -E or -e. For decrypting, the user should input either -D or -d. 

OUTPUT:

Encrypting a file:

Along with the -E or -e input, the spacebar is pressed and then the filename that needs to be encrypted will be inputted whether or not it has the .txt extension after it or not. Make sure that the filename is correct.
Once the file is encrypted, it will make another file with the same filename but with the extension as .crp

Decrypting the file:

When decrypting the encrypted file, the user will have to press the spacebar after entering -D or -d and will input the filename with extension .crp. If the user inputs anything else, the program will end after saying "Cannot open the file." 
Once the file is decrypted, it will make another file with the same filename but with the extension back as .txt


Example of the program:

The user creates an unencrypted file called intro.txt which contains a mixture of characters forming a sentence. Let's say that the user enters this sentence in the file: Hi,<enter>I'm an 18 year old first year university student. If the user wants to decrypt intro.txt, the program will first prompt the user to either encrypt or decrypt the file by saying: "Select -E or -e if you want to encrypt and -D or -d if you want to decrypt: <new line> Enter Your Choice: <tab>". The user will then enter -E intro.txt or -e intro.txt in the program giving the encrypted file, intro.crp, with multiple ASCII characters like this:

48692C0A49276D20616E2031382079656172206F6C64206669727374207965617220756E69766572736974792073747564656E74

Once that is in intro.crp, if the user wants to decrypt it, the program will prompt the user again to either encrypt or decrypt the file by saying: "Select -E or -e if you want to encrypt and -D or -d if you want to decrypt: <new line> Enter Your Choice: <tab>". The user will then enter -D intro.crp or -d intro.crp in the program which will revert it back to Hi, I'm an 18 year old first year university student. Make sure the previous .txt file is deleted. It will not work otherwise.
