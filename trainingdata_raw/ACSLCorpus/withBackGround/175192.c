#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_array(int *p, size_t n) =
      n >= 1 && n <= 200000 &&
      \forall size_t i; 0 <= i < n ==> p[i] >= 1 && p[i] <= n &&
      \forall size_t i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ predicate loop_invariant(int *p, size_t n, size_t i, size_t cnt, size_t index) =
      i <= n &&
      cnt >= 1 &&
      cnt <= i &&
      index < i &&
      valid_array(p, n);
*/

/*@ lemma cnt_bounds:
      \forall int *p, size_t n, size_t cnt;
      valid_array(p, n) && cnt >= 1 && cnt <= n ==> cnt >= 1 && cnt <= n;
*/

/*@ requires valid_array(p, n);
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *p) {
    size_t cnt = 1;
    size_t index = 0;
    size_t i = 1;

    /*@ loop invariant loop_invariant(p, n, i, cnt, index);
        loop invariant i <= n;
        loop assigns i, cnt, index;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert loop_invariant(p, n, i, cnt, index);
        if (p[index] >= p[i]) {
            index = i;
            cnt += 1;
        }
        i += 1;
    }
    //@ assert cnt >= 1 && cnt <= n;
    return cnt;
}
