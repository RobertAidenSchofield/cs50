#include <stdio.h>
#include <cs50.h>
int cubed(int input);


    
int main(void){
    printf("x cubed is equal to: %i\n",cubed(5));
}

int cubed(int input){
    int numCubed = input * input * input;
    return numCubed;
}