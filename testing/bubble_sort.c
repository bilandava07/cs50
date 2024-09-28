int arr = [2,3,6,8,1,9]
int length = 6;

int tmp;
int swap_counter;
int counter = length;

for (int i = 0; i < lenght - 1; i++)
{
    swap_counter = 0;

    for (int z = 0; z < counter; z++)
    {
        if (arr[z] < arr[z+1])
        {
            tmp = arr[z+1];
            arr[z+1] = arr[z];
            arr[z] = tmp;

            swap_counter++;
            counter--;
        }
    }
    if (swap_counter == 0)
    {
        return;
    }
}
