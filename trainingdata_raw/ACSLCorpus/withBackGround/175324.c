#include <stdbool.h>

/*@ predicate in_range(integer v, integer low, integer high) =
      low <= v && v <= high;
*/

/*@ lemma sum_ge_n_lemma:
      \forall integer n, a, b;
        in_range(n, 1, 100) && in_range(a, 1, n) && in_range(b, 1, n) ==>
        (a + b >= n) == ((a + b) >= n);
*/

/*@
  requires 1 <= n <= 100;
  requires 1 <= a <= n;
  requires 1 <= b <= n;
  ensures \result == ((a + b) >= n);
*/
bool func(int n, int a, int b) {
    int state;
    int i;

    state = 0;
    i = 0;
    /*@
      loop invariant 0 <= i <= a;
      loop invariant state == i;
      loop invariant 1 <= n <= 100;
      loop invariant 1 <= a <= n;
      loop invariant 1 <= b <= n;
      loop assigns i, state;
      loop variant a - i;
    */
    while (i < a) {
        state += 1;
        i += 1;
    }

    i = 0;
    /*@
      loop invariant 0 <= i <= b;
      loop invariant state == a + i;
      loop invariant 1 <= n <= 100;
      loop invariant 1 <= a <= n;
      loop invariant 1 <= b <= n;
      loop assigns i, state;
      loop variant b - i;
    */
    while (i < b) {
        state += 1;
        i += 1;
    }

    //@ assert state == a + b;
    return state >= n;
}
