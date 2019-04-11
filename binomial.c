//DOCUMENTATION HERE

#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"

long getNumCalls() {
  return numCalls;
}

long chooseWithMemoization(int n, int k) {

//implement error checking on invalid n and k
  if(k ??? || n ??? ) {
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);
    exit(1);
  }

  int i, j;

  /*
     dynamically allocate (malloc) a matrix of longs to hold values,
     containing flags to indicate if the values has been set or
     not
  */
  long **tableau = (long**)malloc(sizeof(long*) * n);

//malloc
  for(i=0; i<=n; i++) {
     tableau [i] = (long*)malloc(sizeof(long) * k);
//malloc
    for(j=0; j<=k; j++) {
      tableau[i][j] = -1;
    }
  }

  return chooseWithMemoizationRecursive(n, k, tableau);

}

long chooseWithMemoizationRecursive(int n, int k, long **tableau) {

  numCalls++;
  long value;

  //if the value has already been computed, return it...
  //otherwise do recursive logic, determine when to call function again

    return value;
  }

}

long choose(int n, int k) {

  numCalls++;

//implement error checking on invalid n and k
   if(k < 0 || n < k) {
      printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);
      exit(1);
   }

//implement Pascal's Rule to choose
   if (k == 0){
      return 1;
   }
   if (n == k){
      return 1;
   }

   else {
      return choose(n-1, k) + choose(n-1,k-1);
   }

}
