#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float GivenAmount = 0;
    int cents = 0;
    int count = 0;

    do
    {
        printf("How much change are you owed?: ");
        GivenAmount = GetFloat();
    } while (GivenAmount < 0);
    
    GivenAmount *= 100.0;
    cents = (int)round(GivenAmount);
    
    while (GivenAmount >= 25)
    {
        count++;
        GivenAmount -= 25;
    }
    while (GivenAmount >= 10)
    {
        count++;
        GivenAmount -= 10;
    }
    while (GivenAmount >= 5)
    {
        count++;
        GivenAmount -= 5;
    }
    while (GivenAmount >= 1)
    {
        count++;
        GivenAmount -= 1;
    }
    
    printf("%i\n",count);
}
