/*
 * Author: Tyler Furst
 * Date: 04/11/2019
 * This program is where all of the
 * functions are stored for binomialDemo.c to run
 */

#include<stdio.h>
#include<stdlib.h>

#include "binomial.h"

int main(int argc, char **argv) {

  int n;
  int k;

  scanf("%d %d", &n, &k);
  //TODO - scan n and k

  long choice = -1;

  //eventually modify to call memoized choice function
  choice = chooseWithMemoization(n,k);

  printf("choose(%d, %d) = %ld\n", n, k, choice);
  printf("number of calls: %ld\n", getNumCalls());

}
