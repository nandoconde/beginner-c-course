#include <stdio.h>
int main(){

    // Define variables
    char str[100];
    int i;

    // Print to terminal
    printf("\nEnter a value: \n");

    // Read from terminal
    scanf("%s %d", str, &i); //Ampersand because pointer location

    // Print what was read
    printf("You entered %s %d", str, i);

    return 0;
}