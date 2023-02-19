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
    string number = get_string("What is your telephone number ");
    printf("Your name is %s \nYour are %i years old \nYour number is %s \n", name, age, number);
}


//    printf("%i \n", age);
//    printf("%li \n", number);