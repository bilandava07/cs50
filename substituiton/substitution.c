#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
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

    key_length = strlen(argv[1]);

    for (int i = 0; i < length; i++)
    {

    }

    for (int i = 0; i < length; i++)
    {
        if (isalpha(argv[1][i]) == False)
        {
            printf("The key may only contain alphabetic charachters\n");
            return 1;
        }

        // force the chars of the key to uppercase
        argv[1][i] = toupper(argv[1][i]);

        // check if the char is unique
        for (int y = i + 1; y < length; y++)
        {
            if (argv[1][i] == argv[1][y])
            {
                printf("The key must contain each letter exactly once!\n");
                return 1;
            }
        }
    }
}
