#include <stdio.h>
#include <cs50.h>
#include <string.h>

bool lower;
int lenght;

int main(void)
{
    do
    {
        string word = get_string("Word: ");

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

    for (int i = 0; i < lenght; i++)

    bool alphabet = true;
    {
        if (word[i] > word[i++])
        {
            aplhabet = false;
            break;
        }
    }

    if alphabet == false;
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }

}
