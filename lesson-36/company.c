#include <stdio.h>

int main(){
    // Define enum type Company
    enum Company {GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MIROSOFT};

    // Create instances of Company
    enum Company c1 = XEROX;
    enum Company c2 = GOOGLE;
    enum Company c3 = EBAY;

    // Print to terminal
    printf("%d", c1);
    printf("\n%d", c2);
    printf("\n%d\n", c3);
}