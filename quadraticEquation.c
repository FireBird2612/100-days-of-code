/*
Problem: Write a c program to solve quadratic equation.
Date: 09 Dec 2022
Status: Completed
----------------------------------------------------------------------------
Quadratic Equations: https://byjus.com/maths/quadratic-equation-questions/
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, discriminant, root1, root2;
    discriminant = b * b - 4 * a * c;
    printf("Enter the coefficients in the order of a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // comparing with discriminant will help identify the nature of the roots.
    discriminant = b * b - 4 * a * c;

    // if discriminant is greater than 1, roots are real and distinct.
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }

    // if discriminant is 0, roots are real and equal.
    else if (discriminant == 0)
    {
        root1 = root2 = -b / 2 * a;
        printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
    }

    // if discriminant is less than 0, no real roots
    else if (discriminant < 0)
    {
        root1 = -b / (2 * a);
        root2 = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2lf-%.2lfi \n", root1, root2, root1, root2);
    }

    return 0;
}