#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>

double f(double x) 
{
    return exp(-x * x) + 3.0 * x;
}

double integral(double a, double b, int n) 
{   
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i <= n; i++) 
    {
        double x = a + i * h;
        double fx = f(x);

        if (i == 0 || i == n) 
        {
            sum += 0.5 * fx;
        }
        else 
        {
            sum += fx;
        }
    }

    return sum * h;
}

int main() 
{
    double a = 1.0; 
    double b = 2.0;  
    int n = 1000;  

    double result = integral(a, b, n);


    int test_n[] = { 10, 50, 100, 500, 1000, 5000 };
    for (int i = 0; i < sizeof(test_n) / sizeof(test_n[0]); i++) 
    {
        double test_result = integral(a, b, test_n[i]);
        printf("%-10d %-15.8f\n", test_n[i], test_result);
    }

    return 0;
}
