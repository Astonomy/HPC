#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// Function to generate random number between a and b
double random_double(int a, int b) {
    return a + ((double)rand() / (RAND_MAX)) * (b - a);
}

int main(void) {
   int i;
   int total_points = 100000000;
   int circle_points = 0;
   srand((unsigned int) time(0));  // Initialization, should only be called once.

#pragma omp parallel for reduction(+:circle_points)
   for (i=0; i<total_points; ++i){
      double x = random_double(-1.0, 1.0);  // Random x coordinate
      double y = random_double(-1.0, 1.0);  // Random y coordinate
      if(x*x + y*y <= 1) {                 // If point is in the unit circle
         circle_points++;                   // Increment count of points in circle
      }
   }

   double pi = 4.0 * (double)circle_points / total_points;  // Calculate Pi
   printf("Pi is approximately %f\n", pi); // Print the calculated value of Pi
   return 0;
 }