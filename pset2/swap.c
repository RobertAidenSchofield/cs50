#include <stdio.h>

void swap(int x, int y);

int main(void){
    int x = 5, y=7;
    swap(x,y);
    printf("x is equal to:%i\n",x);
    printf("y is equal to:%i\n",y);
    
}

void swap (int x , int y){
    int tmp = x;
    int x = y;
    int y = tmp;
    
}