#include <stdio.h>
#include "profiler.h"
int recursive_fib(int n)
{
    if (n <= 2) return n;
    return recursive_fib(n-1) + recursive_fib(n-2);
}
int recurse_test(int n){
    int res = recursive_fib(n);
    printf("\nrecursive: %d", res);
    return 0;
}

int iter_fib(int n){
    int temp1 = 0,temp2 = 1, temp3;
    for(int i = 0; i < n; i++){
        temp3 = temp2;
        temp2 += temp1;
        temp1 = temp3;
    }
    printf("\niter: %d", temp2);
    return 0;
}

