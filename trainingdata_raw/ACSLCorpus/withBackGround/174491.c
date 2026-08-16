#include <stddef.h>

/*@ predicate is_valid_array(size_t n, size_t *ps) =
      n <= 20 &&
      \forall integer j; 0 <= j < n ==> 1 <= ps[j] && ps[j] <= n && ps[j] != j + 1;
*/

/*@ logic integer ans_bound(integer i) = i - 2; */

/*@ lemma bound_lemma:
      \forall integer i, integer n; 2 <= i <= n ==> ans_bound(i) <= n - 2;
*/

/*@ requires 3 <= k <= n <= 20;
    requires \valid(ps + (0 .. n-1));
    requires is_valid_array(n, ps);
    assigns \nothing;
    ensures \result <= n - 2;
*/
size_t func(size_t n, size_t k, size_t *ps) {
    size_t ans = 0;
    size_t i = 2;
    /*@ loop invariant 2 <= i <= n;
        loop invariant ans <= i - 2;
        loop invariant is_valid_array(n, ps);
        loop assigns ans, i;
        loop variant n - i;
    */
    while (i < n) {
        size_t p1 = ps[i - 1];
        size_t p2 = ps[p1 - 1];
        size_t p3 = ps[p2 - 1];
        if (i + 2 < n && p3 != i + 3) {
            i += 2;
            continue;
        }
        //@ assert ans + 1 <= i - 1;
        ans += 1;
        i += 1;
    }
    //@ assert ans <= n - 2;
    return ans;
}
