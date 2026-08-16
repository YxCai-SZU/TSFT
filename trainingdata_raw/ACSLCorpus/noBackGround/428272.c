#include <stdbool.h>
#include <stddef.h>

/*@
  requires 2 <= N <= 100000;
  requires \valid(A + (0..N-1));
  requires ((2 <= (N) <= 100000) &&
      (\forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= (N)));
  assigns \nothing;
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> \result <= N;
*/
int func(size_t N, int *A) {
    size_t right = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= N;
      loop invariant 0 <= right <= index;
      loop invariant ((2 <= (N) <= 100000) &&
      (\forall integer i; 0 <= i < (N) ==> 1 <= (A)[i] <= (N)));
      loop assigns index, right;
      loop variant N - index;
    */
    while (index < N) {
        //@ assert 0 <= index < N;
        if (A[index] == (int)(right + 1)) {
            right++;
        }
        index++;
    }
    
    if (right == 0) {
        return -1;
    } else {
        return (int)right;
    }
}
