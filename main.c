#include <stdio.h>
#include <math.h>
#include <stdbool.h>

struct complex
{
    double Real, Img; // Img is the imaginory part , real is the real part // SE
};

struct solutions
{
    double a;
    double b;
    bool imaginory;
    struct complex NumeratorComplex;
    double Denominator;
};

struct solutions QuadSolution(double a, double b, double c);
// double RoundDouble(double a, unsigned int n);
int main()
{
    double a, b, c;
    // loop through and then start printing out their solutions!;
    for (int i = 0; i < 10000; i++)
    {
        a = i;
        b = i;
        c = i;
        struct solutions CurrEquation = QuadSolution(a, b, c);
        if (i == 0)
        {
            continue;
        }
        if (CurrEquation.imaginory)
        {
            printf("%gx^2 + %gx + %g = (x - ((%g + (%g)^1/2i) / %g))(x -((%g - (%g)^1/2i) / %g)))\n",
                   a, b, c,
                   CurrEquation.NumeratorComplex.Real, CurrEquation.NumeratorComplex.Img, CurrEquation.Denominator, CurrEquation.NumeratorComplex.Real, CurrEquation.NumeratorComplex.Img, CurrEquation.Denominator);
        }
        else
        {
            printf("%lfx^2 + %lfx + %lf = ((x - %lf)(x -%lf))\n", a, b, c, CurrEquation.a, CurrEquation.b);
        }
    }
}

struct solutions QuadSolution(double a, double b, double c)
{ // (-b +- (b^2 - 4ac)^1/2)/2a;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c != 0)
            {
                printf("the equation is false c does not equal 0");
            }
            else
            {
                printf("0 = 0");
            }
        }
        else
        {
            printf("its a linear equation ");
        }
    }
    double determinant = b * b - 4 * a * c;
    struct solutions _solutions;
    _solutions.imaginory = false;
    if (determinant < 0)
    {
        _solutions.imaginory = true;
        _solutions.NumeratorComplex.Real = -b;
        _solutions.NumeratorComplex.Img = -determinant;
        _solutions.Denominator = 2 * a;
    }
    else
    {
        _solutions.a = (-b + pow(determinant, 1 / 2)) / 2 * a;
        _solutions.b = (-b - pow(determinant, 1 / 2)) / 2 * a;
    }
    return _solutions;
}

// double RoundDouble(double a, unsigned int n)
// {
//     return (double)(round(a * pow(10, n))) / pow(10, n);
// }