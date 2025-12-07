#include <stdio.h>
#include <math.h>

void quadratic(double a, double b, double c);

int main()
{
    // Loop through a, b, c but skip ones with negative discriminant
    for (int a = 1; a <= 10; a++)
    {
        for (int b = -20; b <= 20; b++)
        {
            for (int c = -20; c <= 20; c++)
            {

                double D = b * b - 4 * a * c;
                if (D < 0)
                    continue; // skip imaginary ones

                quadratic(a, b, c);
            }
        }
    }
    return 0;
}

void quadratic(double a, double b, double c)
{
    double D = b * b - 4 * a * c;

    if (D < 0)
    {
        printf("%fx^2 + %fx + %f = IMAGINARY ROOTS\n", a, b, c);
        return;
    }

    double x1 = (-b + sqrt(D)) / (2 * a);
    double x2 = (-b - sqrt(D)) / (2 * a);

    printf("%gx^2 + %gx + %g = (x- (%g))(x - (%g)) \n", a, b, c, x1, x2);
}
