#include <stddef.h>
#include <stdbool.h>

/*@
    requires N > 0;
    requires \valid(A + (0 .. N-1));
    requires \forall integer i; 0 <= i < N ==> A[i] > 0 && A[i] <= 100;
    ensures \result >= 0;
    ensures \result <= N;
    ensures \forall integer i; 0 <= i < N && i % 2 == 0 && A[i] % 2 == 1 ==> \result > 0;
*/
size_t func(size_t N, int *A) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= N;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant (\forall integer j; 0 <= j < (i) && j % 2 == 0 && (A)[j] % 2 == 1 ==> (count) > 0);
        loop invariant ((N) > 0 &&
        \valid((A) + (0 .. (N)-1)) &&
        \forall integer k; 0 <= k < (N) ==> (A)[k] > 0 && (A)[k] <= 100);
        loop invariant i <= N;
        loop assigns i, count;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert ((N) > 0 &&         \valid((A) + (0 .. (N)-1)) &&         \forall integer k; 0 <= k < (N) ==> (A)[k] > 0 && (A)[k] <= 100);
        if (i % 2 == 0 && A[i] % 2 == 1) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
