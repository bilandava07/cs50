#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main (void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


}

int count_letters(text)
{
    int letters = 0;
    int words
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }

    }
}
