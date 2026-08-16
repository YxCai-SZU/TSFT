#include <stddef.h>
#include <stdbool.h>

/*@ predicate exists_zero(int *x, integer len) =
      \exists integer i; 0 <= i < len && x[i] == 0;
*/

/*@ predicate forall_nonzero(int *x, integer bound) =
      \forall integer j; 0 <= j < bound ==> x[j] != 0;
*/

/*@ lemma zero_exists_in_range:
      \forall int *x, integer len;
        len == 5 && exists_zero(x, len) ==>
        \exists integer k; 0 <= k < 5 && x[k] == 0;
*/

/*@
  requires \valid(x + (0 .. 4));
  requires exists_zero(x, 5);
  ensures 1 <= \result <= 5;
  ensures x[\result - 1] == 0;
*/
int func(int *x) {
    int i;
    i = 0;
    /*@
      loop invariant 0 <= i <= 5;
      loop invariant \valid(x + (0 .. 4));
      loop invariant exists_zero(x, 5);
      loop invariant forall_nonzero(x, i);
      loop assigns i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == 0) {
            return i + 1;
        }
        i = i + 1;
    }
    return -1;
}
