#include <stdio.h>
#include <string.h>

int main(void){
    char name[] = "Abraham Licoln";
    printf("%s is %i chars long\n",name,(int) strlen(name));
    printf("%s is %i chars long\n",name,(int) sizeof(name));
}
