#include <stdbool.h>
#include <stdint.h>

/*@
  requires ((N) >= 1 && (N) <= 100 &&
      \valid((A) + (0 .. (N)-1)) &&
      \forall integer i; 0 <= i < (N) ==> (A)[i] >= 1 && (A)[i] <= 100);
  ensures \result >= 0 && \result <= N;
  ensures \forall integer i; 0 <= i < N && ((i) % 2 == 0 && (A)[(i)] % 2 == 1) ==> \result >= 1;
*/
uint32_t func(uint32_t N, uint32_t *A) {
    uint32_t ans = 0;
    uint32_t i = 0;

    /*@
      loop invariant 0 <= i <= N;
      loop invariant ans >= 0;
      loop invariant ans <= i;
      loop invariant \forall integer j; 0 <= j < i ==> A[j] >= 1 && A[j] <= 100;
      loop invariant \forall integer j; 0 <= j < i && ((j) % 2 == 0 && (A)[(j)] % 2 == 1) ==> ans >= 1;
      loop assigns i, ans;
      loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        if (i % 2 == 0 && A[i] % 2 == 1) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
