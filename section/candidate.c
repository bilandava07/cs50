#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidates[3];
    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate("Enter a candidate: ");
    }
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", candidates[i].name);
        printf("%i\n", candidates[i].votes);

    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;

    c.name = get_string("Enter a name: ");
    c.votes = get_int("Number of votes: ");
    return c;
}