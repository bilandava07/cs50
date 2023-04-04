// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);
int length;

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word \n");
        return 1;
        length = strlen(argv[1]);
        string word = replace(argv[1]);

    }
}

string replace(string word)
{
    for (int i = 0; i < length; i++)
    {
        int n = word[1];
        switch(n)
        {
            case 101:
                word[i] = 3;
                 break;
            case 97:
                word[i] = 6;
                break;
            case 105:
                word[i] = 1;
                break;
            case 111:
                word[i] = 0;
                break;
        }
    }
    return word;
}
