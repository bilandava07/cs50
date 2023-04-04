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
        int word = replace(argv[1])

    }
}

string replace(string word)
{
    for (int i = 0; i < length; i++)
    {
        switch(word[i])
        {
            case e:
                word[i] = 3;
            case a:
                word[i] = 6;
            case i:
                word[i] = 1;
            case o:
                word[i] = 0;
        }
    }
    return word;
}
