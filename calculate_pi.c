# include <stdio.h>
# include <stdlib.h>
# include <omp.h>
# include <time.h>

double i = 0;
double s = 0;

void single_task()
{
    double a = ((double)rand()/RAND_MAX)*(1-0) + 0;
    double b = ((double)rand()/RAND_MAX)*(1-0) + 0;
    if ( a*a + b*b < 1)
        i = i + 1;
    s = s + 1;
}

int main()
{
    srand((unsigned)time(NULL));
    #pragma omp parallel for schedule(static,4)
    for (  int p = 0 ; p < 1000000 ; p ++)
    {
        single_task();
    }
    printf("pi=%.6f", 4*i/s);
    return 0;
}