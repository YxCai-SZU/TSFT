#include <stddef.h>
#include <stdbool.h>

/*@ requires (1 <= (N) && (N) <= 100 &&
      1 <= (M) && (M) <= 100 &&
      1 <= (X) && (X) <= (N) - 1);
    requires (\forall integer i; 0 <= i < (M) ==> 1 <= (A)[i] && (A)[i] <= 100);
    requires (\forall integer i; 0 <= i < (M) ==> (A)[i] != (X));
    ensures \result >= 0 && \result <= M;
    assigns \nothing;
*/
size_t func(size_t N, size_t M, size_t X, int *A) {
    size_t l = 0;
    size_t r = 0;
    size_t i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (M) &&
      (l) <= (i) && (r) <= (i) &&
      (l) + (r) <= (i) &&
      \forall integer j; 0 <= j < (i) ==> ((A)[j] > (X) ==> (r) > 0) && ((A)[j] < (X) ==> (l) > 0));
        loop assigns i, l, r;
        loop variant M - i;
    */
    while (i < M) {
        int a = A[i];
        
        //@ assert 1 <= a && a <= 100;
        //@ assert a != X;
        
        if (a > X) {
            r = r + 1;
        }
        if (a < X) {
            l = l + 1;
        }
        i = i + 1;
    }
    
    size_t min_val = (r < l) ? r : l;
    
    //@ assert min_val >= 0 && min_val <= M;
    return min_val;
}
