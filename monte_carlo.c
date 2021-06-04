#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}

float mc_pi(int n)
{
	int i;
	float rand_x, rand_y, origin_dist, pi,pi1;
	int c_points = 0, s_points = 0;
  
   
    	for (i = 0; i < n ; i++) {
  
      
        rand_x = frandom();
        rand_y = frandom();
  
  
        origin_dist = rand_x * rand_x + rand_y * rand_y;
  
     
        if (origin_dist <= 1)
            c_points++;
  
       
        s_points++;
        }
  
        pi1 = (4 * c_points) / s_points;
      	pi=(float)pi1;
	return pi;

}



