#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Try again!\n");
        return 1;
    }
    int k = atoi(argv[1]);
    
    if (k < 0)
    {
        printf("must be positive !\n");
        return 1;
    }
    string c = GetString();
   
    for (int i = 0, n = strlen(c); i < n; i++)
    {
        if islower(c[i])
            
            printf("%c",(((c[i] + k) - 97) % 26) + 97);
        
        else if isupper(c[i])
            
            printf("%c",(((c[i] + k) - 65) % 26) + 65);
                    
        else  
            
            printf("%c",c[i]);
        
    }
    
    printf("\n");

    return 0;
}