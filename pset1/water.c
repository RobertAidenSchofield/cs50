#include <stdio.h>
#include <cs50.h>


int main(void)

{
    int ounces, bottles, minutes;
    
    do
    {
    printf("How many minutes did you spend in the shower?: ");
    minutes = GetInt();
    }
    
    while (minutes < 1);
    
    ounces = (minutes * 192);
    bottles = (ounces / 16);
    printf("Your shower was about %i bottles of water!\n", bottles);

}