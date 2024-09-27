# include <stdio.h>
# include <stdlib.h>
# include <omp.h>
# include <time.h>

double i = 0;
double s = 0;
double sum = 0;

void single_task()
{
    double a = ((double)rand()/RAND_MAX)*(1-0) + 0;
    double b = ((double)rand()/RAND_MAX)*(1-0) + 0;
    if ( a*a + b*b < 1)
        i = i + 1;
    s = s + 1;
}

void single()
{
//    clock_t start_t,finish_t;
//    double total_t = 0 ;
    srand((unsigned)time(NULL));
//    start_t = clock();
    #pragma omp parallel for schedule(static,4)
    for (  int p = 0 ; p < 10000000 ; p ++)
    {
        single_task();
    }
//    finish_t = clock();
//    total_t = (double)(finish_t - start_t) / CLOCKS_PER_SEC;
//    printf("time=%.6f\n",total_t);
//    printf("%.20f\n", 4*i/s);
}

int main()
{
    for(int time;time < 10;time ++)
    {
        single();
        sum = sum + 4*i/s;
        i = 0;
        s = 0;
    }
    printf("pi on average is %.20f\n", sum/10);
    return 0;
}