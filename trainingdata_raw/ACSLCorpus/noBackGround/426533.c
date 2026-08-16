#include <stdbool.h>
#include <stddef.h>

/*@ requires ((N) >= 1 && (N) <= 1000000 &&
      (M) >= 1 && (M) <= 10000);
    requires (\forall integer i; 0 <= i < (M) ==> (A)[i] >= 1 && (A)[i] <= 10000);
    requires \valid(A + (0 .. M-1));
    assigns \nothing;
    ensures \result >= -1;
    ensures \result <= N;
*/
int func(int N, int M, int *A) {
    int sum = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= (size_t)M;
        loop invariant sum >= 0;
        loop invariant sum <= (int)i * 10000;
        loop invariant \forall size_t j; 0 <= j < i ==> A[j] >= 1 && A[j] <= 10000;
        loop assigns sum, i;
        loop variant (size_t)M - i;
    */
    while (i < (size_t)M) {
        //@ assert A[i] >= 1 && A[i] <= 10000;
        sum += A[i];
        i++;
    }
    
    if (N >= sum) {
        //@ assert N - sum >= 0 && N - sum <= N;
        return N - sum;
    } else {
        return -1;
    }
}
