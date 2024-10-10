#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>

// Function to count number of primes under n
int countPrimes(int n)
{
    char *is_prime = (char*) malloc((n+1) * sizeof(char));
    for (int i = 2; i <= n; i++) is_prime[i] = 1;

    int n1 = sqrt(n);
    #pragma omp parallel for schedule(dynamic)
    for (int p = 2; p <= n1; p++)
    {
        if (is_prime[p] == 1) {  // If prime[p] is not changed, then it is a prime
            for (int i = p * p; i <= n; i += p) is_prime[i] = 0; // Update all multiples of p
        }
    }

    int count = 0;
    #pragma omp parallel for reduction(+:count)
    for (int p=2; p<n; p++) {
        if (is_prime[p]) count++;
    }

    free(is_prime);

    return count;
}

// Driver Program
int main() {
    int n = 100000;
    printf("There's %d prime numbers under 100000\n",countPrimes(n));
    return 0;
}