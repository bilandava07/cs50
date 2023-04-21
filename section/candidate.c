#include <stdio.h>
#include <cs50.h>

typedef struct
{
    string name;
    int votes;
}
candidate;

int main(void)
{
    candidate president = get_candidate("Enter a candidate: ");

}

candidate get_candidate(string prompt)
{

}