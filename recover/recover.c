#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Correct usage: ./recover <name of the file>");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        return 1;
    }

    int counter = 1;

    BYTE buffer =;

    while (fread(buffer, 1, BLOCK_SIZE, argv[1]) == BLOCK_SIZE)
    {
        fread(buffer, 1, BLOCK_SIZE, argv[1]);

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && (buffer[3] & 0xf0) == 0xe0)
        {
            *char *filename = malloc(16);
            if (filename == NULL)
            {
                return 1;
            }
            sprintf(filename, "%03i.jpg", counter);

        }

    }


}