#include <stdio.h>

int main()
{

    float b;
    float h;

    printf("\nEnter side: ");
    scanf("%f", &b);
    printf("\nNow enter height: ");
    scanf("%f", &h);

    printf("\nThe rectangle area is: %5.2f", b*h);
    printf("\nThe rectangle perimeter is: %5.2f\n", 2*(b+h));
}