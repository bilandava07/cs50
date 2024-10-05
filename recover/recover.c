#include <stdio.h>
#include <stdlib.h>

#define BLOCK 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover [name of the forensic image]\n");
    }

    // Open the memory card file for reading

    FILE *card = fopen( "card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open the file!\n");
        return 2;
    }
    
}
