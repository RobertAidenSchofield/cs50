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
    string l = argv[1];
    for (int i = 0, n = strlen(l); i < n; i++)
    {
        if (!isalpha (l[i]))
        {
            printf("try again!\n");
            return 1;
        }
    }
    
    string code = GetString();
        
    int key = 0;
        
    for (int i = 0, n = strlen(code); i < n; i++)
    {
        key = key % strlen(argv[1]);
            
        if isalpha(code[i])
            
        {
            if (islower(code[i]) && islower(argv[1][key]))
                printf("%c",(((code[i] - 97) + (argv[1][key]) - 97) % 26) + 97);
            else if (isupper(code[i]) && isupper(argv[1][key]))
                printf("%c",(((code[i] - 65) + (argv[1][key]) - 65) % 26) + 65);
            else if (islower(code[i]) && isupper(argv[1][key]))
                printf("%c",(((code[i] - 97) + (argv[1][key]) - 65) % 26) + 97);
            else if (isupper(code[i]) && islower(argv[1][key]))
                printf("%c",(((code[i] - 65) + (argv[1][key]) - 97) % 26) + 65);  
            key++;
        }
        
        else
        {
            printf("%c",code[i]);
        }
        
    }
    printf("\n");
   
    
}