#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int calculate_score(string word);
int points [] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

int main(void)
{
    string p1 = get_string("Player1: ");
    string p2 = get_string("Player2: ");

    int p1_score = calculate_score(p1);
    int p2_score = calculate_score(p2);

    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_score < p2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int calculate_score(string word)
{
    int sum = 0;
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        sum += word[i] - 65 + points[i];
    }
    return sum;
}
