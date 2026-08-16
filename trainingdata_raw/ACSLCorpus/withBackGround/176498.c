#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_array(int32_t *a, integer n) =
      n > 0 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer j; 0 <= j < n ==> 1 <= a[j] && a[j] <= 100;
*/

/*@ predicate ans_invariant(integer i, integer n, integer ans) =
      i >= 0 && i <= n && ans >= 0 && ans <= i;
*/

/*@ lemma ans_bounded: 
      \forall integer n, ans; 
      ans_invariant(n, n, ans) ==> ans >= 0 && ans <= n;
*/

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer j; 0 <= j < n ==> 1 <= a[j] && a[j] <= 100;
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
uint32_t func(uint32_t n, int32_t *a) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop invariant ans <= i;
        loop invariant valid_array(a, n);
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert valid_array(a, n);
        if ((i % 2) == 0 && (a[i] % 2 == 0)) {
            ans += 1;
        }
        i += 1;
    }
    //@ assert ans_invariant(i, n, ans);
    return ans;
}
