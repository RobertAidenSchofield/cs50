#include <stdio.h>
#include <cs50.h>
#define LETTERS_IN_ALPHA 26
#include <string.h>
#include <ctype.h>

int main(void){
    char alphabet[LETTERS_IN_ALPHA];
    for(int i = 0; i < LETTERS_IN_ALPHA;i++){
        alphabet[i] = (char) ('a' + i);
        printf("%c\n",toupper(alphabet[i]));
    }
    
}