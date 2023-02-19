#include <stdio.h>
#include <cs50.h>

    // program has ask a user for a name, an age and a phone number//
    // name - string //
    // age - int //
    // phone number - int //

int main(void)
{
    // ask for a name (str)//
    string name = get_string("What is your name? ");
    int age = get_int("How old are you? ");
    long number = get_long("What is your telephone number ");
    printf("%s \n%i \n%li \n", name, age, number);
}


//    printf("%i \n", age);
//    printf("%li \n", number);