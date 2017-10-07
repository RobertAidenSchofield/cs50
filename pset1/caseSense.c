/*
Prompt user for a string "Give me a message:"
store the input as a variable string
ask user for more input, upper case, lower case, swapcase
remember which they chose - store as variable Case
iterate throught each char in string, checking the case using a loop
    if char is upper case then  
        if our case is lowercase or swap then 
            output the lower case version of the char  
    else if the char is lower case then
        if our case is upper case or swap then
            output the upper case version of the char
    else if neither
        output the char
output the new line
*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main( )
{
    printf("Give me a message: ");
    string str = GetString ();
    printf("Select (U)pper, (L)ower, (S)wap case: ");
    char selection = GetChar();
    
    int length = strlen (str);
    for (int i = 0; i < length; i++)
    {
        else if (str [i] >= 'a' && str [i] <= 'z' )
        {
            if( selection == 'U' || selection =='S' )
            {
                char c = (char) ((int) str[i] + 32);
                printf ("%c",c);
             }
            else
            {
                 printf ("%c",str[i]);
            }
        }
        else
        {
            printf ("%c",str[i]);
        }
    }
    printf("\n\n\n\n\n\n\n");
    
    return 0;
}