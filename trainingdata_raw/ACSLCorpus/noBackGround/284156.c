#include <stdbool.h>
#include <stddef.h>

/*@
  requires \valid(A+(0..N-1));
  requires ((N) >= 2 && (N) <= 100000 &&
      \forall integer i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= (N) &&
      \forall integer i, j; 0 <= i < j < (N) ==> (A)[i] != (A)[j]);
  assigns \nothing;
  ensures \result >= 0 && \result <= N;
*/
int func(size_t N, int *A) {
    int ans = 0;
    size_t i = 0;
    int a0 = 0;
    int a1 = 0;

    /*@
      loop invariant (0 <= (i) && (i) <= (N) &&
      0 <= (ans) && (ans) <= (int)(i) &&
      (a0) >= 0 && (a1) >= 0 &&
      (N) >= 2 && (N) <= 100000 &&
      \forall integer k; 0 <= k < (N) ==> (A)[k] >= 1 && (A)[k] <= (N) &&
      \forall integer k, l; 0 <= k < l < (N) ==> (A)[k] != (A)[l]);
      loop invariant i <= N;
      loop assigns i, ans, a0, a1;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert (0 <= (i) && (i) <= (N) &&       0 <= (ans) && (ans) <= (int)(i) &&       (a0) >= 0 && (a1) >= 0 &&       (N) >= 2 && (N) <= 100000 &&       \forall integer k; 0 <= k < (N) ==> (A)[k] >= 1 && (A)[k] <= (N) &&       \forall integer k, l; 0 <= k < l < (N) ==> (A)[k] != (A)[l]);
        if (i == N - 1) {
            break;
        }
        if (A[i] == 1) {
            a0 = 1;
            ans += 1;
        } else if (A[i] == 2) {
            a1 = 1;
            ans += 1;
        } else {
            if (a0 == 1) {
                ans += 1;
                a0 = 0;
            } else if (a1 == 1) {
                ans += 1;
                a1 = 0;
            }
        }
        i += 1;
        //@ assert (0 <= (i) && (i) <= (N) &&       0 <= (ans) && (ans) <= (int)(i) &&       (a0) >= 0 && (a1) >= 0 &&       (N) >= 2 && (N) <= 100000 &&       \forall integer k; 0 <= k < (N) ==> (A)[k] >= 1 && (A)[k] <= (N) &&       \forall integer k, l; 0 <= k < l < (N) ==> (A)[k] != (A)[l]);
    }
    //@ assert ans >= 0 && ans <= N;
    return ans;
}
