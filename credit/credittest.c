#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card;
    card = get_long("Number: ");

    card = card % 10;

    printf("%li \n", card);

}