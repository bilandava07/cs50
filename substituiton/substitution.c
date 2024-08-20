#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // validate input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 charachters\n");
        return 1;
    }

    int key_length = strlen(argv[1]);

    // validate key
    for (int i = 0; i < key_length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("The key may only contain alphabetic charachters\n");
            return 1;
        }

        // force the chars of the key to uppercase
        argv[1][i] = toupper(argv[1][i]);

        // check if the char is unique
        for (int y = i + 1; y < key_length; y++)
        {
            if (argv[1][i] == argv[1][y])
            {
                printf("Key must not containe repeated charachters\n");
                return 1;
            }
        }
    }
    // get the plaintext
    string plain = get_string("plaintext: ");

    // initialize the ciphertext
    char cipher[strlen(plain) + 1];

    for (int i = 0, length_p = strlen(plain); i < length_p; i++ )
    {
        if (isalpha(plain[i]))
        {
            if (islower(plain[i]))
            {
                cipher[i] = tolower(argv[1][plain[i] - 97]);
            }
            else
            {
                cipher[i] = argv[1][plain[i] - 65];
            }
        }
        else
        {
            cipher[i] = plain[i];
        }
    }

    

    printf("ciphertext: %s\n", cipher);
    return 0;

}
