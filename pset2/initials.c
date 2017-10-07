#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main (void)
{
    string c = GetString();
    printf("%c", toupper(c[0]));
    for (int i = 0, n = strlen(c); i < n; i++)
    {
        if(c[i] == ' ' && c[i+1] != '\0')
        {
            printf("%c", toupper(c[i + 1]));
            i++;
        }
    }
    printf("\n");
}