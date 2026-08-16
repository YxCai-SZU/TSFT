#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires \valid(x + (0 .. 4));
  requires (\exists integer j; 0 <= j < (5) && (x)[j] == 0);
  ensures \result >= 1 && \result <= 5;
  ensures x[\result - 1] == 0;
*/
int func(int64_t *x) {
    int ans = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \valid(x + (0 .. 4));
      loop invariant (\exists integer j; 0 <= j < (5) && (x)[j] == 0);
      loop invariant (((ans) == 0 && \forall integer k; 0 <= k < (i) ==> (x)[k] != 0) ||
      ((ans) >= 1 && (ans) <= (5) && (x)[(ans) - 1] == 0));
      loop assigns ans, i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            ans = (int)(i + 1);
            break;
        }
        i++;
    }
    //@ assert ans >= 1 && ans <= 5;
    //@ assert x[ans - 1] == 0;
    return ans;
}
