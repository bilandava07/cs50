// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    int n = NUM_CITIES;

    typedef struct
    {
        int min;
        int index;
        string name;
    }
    min;

    typedef struct
    {
        int degree;
        string name;
    }
    place_holder;

    min.min = temps[0].temp;
    min.name = temps[0].city;
    min.index = 0;


    int index;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (temps[j].temp < min.min)
            {
                min.min = temps[j].temp;
                min.name = temps[j].city;
                min.index = j;
            }
        }

        place_holder.degree = temps[i]temp;
        place_holder.name = temps[i].city;


        temps[i].temp = min;
        temps[i].city = min_name;

        temps[min.index].temps = place_holder.degree;
        temps[min.index].city = place_holder.name;

    }
}
