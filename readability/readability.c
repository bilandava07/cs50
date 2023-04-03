#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int length;

int count_letters(string text);

int main(void)
{
    string text = get_string("Text: ");

    length = strlen(text);
    printf("The text is %i letters long \n", length);

    //printf("Text: %s \n", text);
}

int count_letters(string text)
{
    return 0;

}
