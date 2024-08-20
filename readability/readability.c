#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main (void)
{
    string text = get_string("Text: ");

    int letters = 0;
    int words = 0;
    int sentences = 0;

    //count everything in one loop instead of going through the same string 3 times with different functions (my inital approach)
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (isblank(text[i]))
        {
            words++;
        }
        else if (text[i] == '!' or text[i] == '.' or text[i] == '?')
        {
            sentences++;
        }
    }

    //add 1 to words, as there is no blank space at the end of the string
    words++;

    float avrg_letters = (float) letters / (float) words;
    

}


