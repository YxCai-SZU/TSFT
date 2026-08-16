#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_array(uint64_t *a, integer n) =
      n >= 1 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 1000000000;
*/

/*@ predicate loop_invariant(uint64_t *a, integer n, uint64_t k,
                             integer i, uint64_t cnt) =
      0 <= i <= n &&
      cnt <= i &&
      cnt <= n &&
      n >= 1 &&
      k >= 1 &&
      valid_array(a, n);
*/

/*@ lemma cnt_bound: \forall uint64_t *a, integer n, uint64_t k,
                        integer i, uint64_t cnt;
      loop_invariant(a, n, k, i, cnt) ==> cnt <= n;
*/

/*@ requires n >= 1 && k >= 1;
    requires \valid(a + (0 .. n-1));
    requires valid_array(a, n);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k, uint64_t *a) {
    uint64_t cnt = 0;
    uint64_t i = 0;
    
    /*@ loop invariant loop_invariant(a, n, k, i, cnt);
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert loop_invariant(a, n, k, i, cnt);
        if (a[i] % k == 0) {
            cnt = cnt + 1;
        }
        i = i + 1;
    }
    //@ assert cnt <= n;
    return cnt;
}
