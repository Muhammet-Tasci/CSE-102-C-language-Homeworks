#include <stdio.h>

int main () {

float diameter;
float area;
float pi = 3.14;

printf("Please enter the diameter of sphere: ");
scanf("%f", &diameter);

area = 4 * pi * (diameter / 2) * (diameter / 2);

printf("r = %.2f\n", diameter / 2);
printf("Area of sphere: %.2f\n", area);

return 0;

}


