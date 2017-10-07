#include <stdio.h>
#include <cs50.h>

int main(void)

{
    int height;
    do
    {
        printf("Give me the height of your pyramid: ");
        height = GetInt();
    }
    while (height < 1 || height > 23);
    
    for (int i = 0; i < height;i++)
    {
        int hashes = (i + 2);
        int spaces = (height + 1 - hashes);
        
        for (int s = 0; s < spaces; s++)
        {
            printf(" ");
        }
        
        for (int h = 0; h < hashes; h++)
        {
            printf("#");    
        }
        
        printf("\n");
    }
    
}
