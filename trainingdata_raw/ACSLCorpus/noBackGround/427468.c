#include <stddef.h>
#include <stdbool.h>

/*@
  requires N >= 1 && N <= 100;
  requires \valid(A + (0 .. N-1));
  requires \forall integer i; 0 <= i < N ==> 1 <= A[i] && A[i] <= 100;
  assigns \nothing;
  ensures \result >= 0 && \result <= N;
*/
size_t func(size_t N, int *A) {
    size_t count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= N;
      loop invariant count <= i;
      loop invariant ((N) >= 1 && (N) <= 100 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer j; 0 <= j < (N) ==> 1 <= (A)[j] && (A)[j] <= 100);
      loop assigns i, count;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N ==> 1 <= A[i] && A[i] <= 100;
        if (A[i] % 2 == 1 && i % 2 == 0) {
            //@ assert count + 1 <= i + 1;
            count += 1;
        }
        //@ assert count <= i + 1;
        i += 1;
    }
    //@ assert ((count) >= 0 && (count) <= (N));
    return count;
}
