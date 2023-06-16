#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        printf("Correct usage: ./recover <name of the file>");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");

    


}