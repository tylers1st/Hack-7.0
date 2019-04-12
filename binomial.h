static long numCalls = 0;

//returns the number of function calls that were necessary to execute Pascal's Rule in choosing
long getNumCalls();

/**
 * Runs Pascal's version of
 * binomial coefficient
 **/
long choose(int n, int k);

//Allocates memory for its subsequent recusive call of chooseWithMemoizationRecursive
long chooseWithMemoization(int n, int k);

/**
 * Runs Pascal's version of
 * binomial coefficient
 * while also storing the values
 * previously computed
 **/
long chooseWithMemoizationRecursive(int n, int k, long **tableau);
