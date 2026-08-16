#include <stdbool.h>
#include <stddef.h>

/*@ requires ((N) >= 1 && (N) <= 1000000 &&
      (M) >= 1 && (M) <= 10000 &&
      \valid((A) + (0 .. (M)-1)) &&
      \forall integer i; 0 <= i < (M) ==> (A)[i] >= 1 && (A)[i] <= 10000);
    ensures \result >= -1 && \result <= N;
    assigns \nothing;
*/
long func(long N, long M, const long *A) {
    long sum = 0;
    size_t index = 0;
    long result;
    
    /*@ loop invariant (0 <= (index) <= (M) &&
      (sum) >= 0 &&
      (sum) <= (index) * 10000 &&
      \valid((A) + (0 .. (M)-1)) &&
      \forall integer k; 0 <= k < (index) ==> (A)[k] >= 1 && (A)[k] <= 10000);
        loop assigns sum, index;
        loop variant M - index;
    */
    while (index < (size_t)M) {
        //@ assert 0 <= index < M;
        sum += A[index];
        index++;
    }
    
    //@ assert sum >= 0 && sum <= M * 10000;
    if (N - sum >= 0) {
        result = N - sum;
        //@ assert result >= 0 && result <= N;
        return result;
    } else {
        result = -1;
        //@ assert result >= -1 && result <= N;
        return result;
    }
}
