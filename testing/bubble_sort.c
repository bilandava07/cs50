#include <stdio.h>


int arr [6] = {2,3,6,8,1,9};

int tmp;
int swap_counter;
int length = 6;
int counter = 6;


int main(void)
{

    for (int i = 0; i < length; i++)
    {
        swap_counter = 0;

        for (int z = 0; z < counter-1; z++)
        {
            if (arr[z] < arr[z+1])
            {
                tmp = arr[z+1];
                arr[z+1] = arr[z];
                arr[z] = tmp;

                swap_counter++;
            }
        }
        if (swap_counter == 0)
        {
            break;
        }

        for (int y = 0; y < 6; y++)
        {
            printf("%i ", arr[y]);
        }
        printf("\n");
        counter--;
    }

}
