#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool lower;
int lenght;

int main(void)
{
    string word;
    do
    {
        word = get_string("Word: ");

        lenght = strlen(word);
        for (int i = 0; i < lenght; i++)
        {
            lower = true;
            if (word[i] < 97 || word[i] > 122)
            {
                lower = false;
                break;
            }
        }
    }
    while (lower == false);
    printf("lower indeed \n");

    bool alphabet = true;
    for (int i = 0; i < lenght; i++)
    {
        if (word[i] > word[i+1])
        {
            alphabet = false;
            break;
        }
    }

    if (alphabet == false)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

}
