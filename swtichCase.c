/*
PROBLEM: Write a program to calculate the area of different geometrical figures
- circle, triangle, trapezoid, square and rectangle
The program shoudl ask the user to enter the code for which user wants to find out the area.
- 't' triangle
- 'z' trapezoid
- 'c' circle
- 's' square
- 'r' rectangle

DATE: 10 Dec 2022

STATUS: Completed
-----------------------------------------------------------------------------------------------
*/

#include <stdio.h>

// function prototype
void calculate_Area_Triangle();
void calculate_Area_Trap();
void calculate_Area_Circ();
void calculate_Area_Sq();
void calculate_Area_Rect();

int main()
{
    // Store the input from user.
    char usrIp;
    const char tri = 't', trap = 'z', cir = 'c', sq = 's', rect = 'r';

    printf("\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*\nTo calculate the area, please enter the code specific code for the following...\n");
    printf("\'t\' - triangle\n\'z\' - trapezoid\n\'c\' - circle\n\'s\' - square\n\'r\' - rectangle\n\nEnter your code here: ");
    scanf("%c", &usrIp);
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*-*-*-*-*\n");

    switch (usrIp)
    {
    case tri:
        calculate_Area_Triangle();
        break;

    case trap:
        calculate_Area_Trap();
        break;

    case cir:
        calculate_Area_Circ();
        break;

    case sq:
        calculate_Area_Sq();
        break;

    case rect:
        calculate_Area_Rect();
        break;

    default:
        printf("Invalid! Make sure you have entered the character mentioned above.\n");
    }

    return 0;
}

void calculate_Area_Triangle()
{
    float height, base, area;

    printf("Enter height(h) of the triangle:");
    scanf("%f", &height);
    printf("Enter base(b) of the triangle:");
    scanf("%f", &base);

    area = (height * base) / 2;
    printf("The area of the traingle is: %.2f\n\n", area);
}

void calculate_Area_Trap()
{
    float base1, base2, height, area;

    printf("Enter height(h) of the trapezoid:");
    scanf("%f", &height);
    printf("Enter base1(b1) of the trapezoid:");
    scanf("%f", &base1);
    printf("Enter base2(b2) of the trapezoid:");
    scanf("%f", &base2);

    area = (base1 * base2) / 2 * height;
    printf("The area of the trapezoid is: %.2f\n\n", area);
}

void calculate_Area_Circ()
{
    float radius, area;

    printf("Enter radius(r) of the circle:");
    scanf("%f", &radius);

    area = 3.14 * radius * radius;

    printf("The area of the circel is: %.2f\n\n", area);
}
void calculate_Area_Sq()
{
    float side, area;

    printf("Enter side(a) of the square:");
    scanf("%f", &side);

    area = side * side;

    printf("The area of the square is: %.2f\n\n", area);
}

void calculate_Area_Rect()
{
    float length, width, area;

    printf("Enter length(l) of the rectangle:");
    scanf("%f", &length);
    printf("Enter width(w) of the rectangle:");
    scanf("%f", &width);

    area = length * width;

    printf("\nThe area of the rectangle is: %.2f\n\n", area);
}