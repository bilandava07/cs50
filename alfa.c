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

    for (int i = 0; i < lenght - 1; i++)
    {
        if (word[i] > word[i + 1])
        {
            printf("No \n");
            return 0;
        }
    }

    printf("Yes\n");
    return 0;
}
