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

    string key[26];

    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpah(argv[1][i]) == False)
        {
            printf("The key may only contain alphabetic charachters\n");
            return 1;
        }
        key[i] = toupper(argv[1][i]);
    }
}
