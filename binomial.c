/*
 * Author: Tyler Furst
 * Date: 04/11/2019
 * This program is where all of the
 * functions are stored for binomialDemo.c to run
 */
#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"

long getNumCalls() {
  return numCalls;
}

long chooseWithMemoization(int n, int k) {

//implement error checking on invalid n and k
  if(k < 0 || n < 0 ) {
    printf("invalid inputs: choose(%d, %d), quitting on you...\n", n, k);
    exit(1);
  }

  int i, j;

  /*
     dynamically allocate (malloc) a matrix of longs to hold values,
     containing flags to indicate if the values has been set or
     not
  */
  long **tableau = (long**)malloc(sizeof(long*) * (n+1));

//malloc
  for(i=0; i<=n; i++) {
    tableau[i] = (long*)malloc(sizeof(long) * (k+1));
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
  
  if (k == 0){
	  tableau[n][k] = 1;
      return 1;
  }
  if (n == k){
	  tableau[n][k] = 1;
      return 1;
  }
  if (tableau[n][k] != -1){
	  return tableau[n][k];
  }
  
  else {
	  tableau[n][k] = chooseWithMemoizationRecursive(n-1,k,tableau) + chooseWithMemoizationRecursive(n-1,k-1,tableau);
	  value = tableau[n][k];
  }

  return value;
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
