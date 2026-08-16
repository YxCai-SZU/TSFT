#include <stddef.h>
#include <stdbool.h>

/*@
  requires N >= 3 && N <= 200000;
  requires \valid(p + (0 .. N-1));
  requires (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N) &&
      \forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
  assigns \nothing;
  ensures \result <= N - 2;
*/
size_t func(size_t N, const int *p) {
    size_t ans = 0;
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= N - 1;
      loop invariant ans <= i - 1;
      loop invariant ans <= N - 2;
      loop invariant (\forall integer i; 0 <= i < (N) ==> 1 <= (p)[i] <= (N) &&
      \forall integer i, j; 0 <= i < j < (N) ==> (p)[i] != (p)[j]);
      loop assigns ans, i;
      loop variant N - i;
    */
    while (i < N - 1) {
        //@ assert p[i-1] != p[i] && p[i] != p[i+1];
        if (p[i - 1] < p[i] && p[i] < p[i + 1]) {
            ans += 1;
            //@ assert ans <= i;
        } else if (p[i - 1] > p[i] && p[i] > p[i + 1]) {
            ans += 1;
            //@ assert ans <= i;
        }
        i += 1;
        //@ assert ans <= i - 1;
    }
    return ans;
}
