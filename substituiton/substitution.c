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

    // validate key for invalid chars
    for (int i = 0; i < key_length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("The key may only contain alphabetic characters\n");
            return 1;
        }
        // force the chars of the key to uppercase
        argv[1][i] = toupper(argv[1][i]);
    }

    for (int i = 0; i < key_length; i++)
    {
        // check if the char is unique
        for (int y = i + 1; y < key_length; y++)
        {
            if (argv[1][i] == argv[1][y])
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }
    // get the plaintext
    string text = get_string("plaintext: ");

    // replace plaintext with ciphertext
    for (int i = 0, length_p = strlen(text); i < length_p; i++ )
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                text[i] = tolower(argv[1][text[i] - 'a']);
            }
            else
            {
                text[i] = argv[1][text[i] - 'A'];
            }
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
