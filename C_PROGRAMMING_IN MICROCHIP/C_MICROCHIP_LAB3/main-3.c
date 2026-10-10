#include <stdio.h>
#include <stdlib.h>

// factorial function
double facto(int x)
{
    double fact = 1.0;
    for (int i = 1; i <= x; i++)
    {
        fact = fact * i;
    }
    return fact;
}

// power function (x^n)
double power(int x, int n)
{
    double p = 1.0;
    for (int i = 1; i <= n; i++)
    {
        p = p * x;
    }
    return p;
}

double main()
{
    int x, n = 0;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    double term = 1.0;
    double sum = 0.0;

    printf("Terms\tApproximation\n");

    while (1)
    {
        // compute current term: x^n / n!
        term = power(x, n) / facto(n);

        // stop if term is very small (absolute value)
        if (term < 0.0000001 && term > -0.0000001)
        {
            break;
        }

        sum = sum + term;

        printf("%d\t%.7f\n", n + 1, sum);

        n++;
    }

    return 0;
}
