#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Correct usage: ./recover <name of the file>");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");

    BYTE buffer = [];

    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {

    }


}