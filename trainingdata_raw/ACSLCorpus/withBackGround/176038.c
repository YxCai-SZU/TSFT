#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_array(integer n, int32_t *a) =
      n >= 1 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ logic integer count_odds(integer n, int32_t *a, integer idx) =
      idx <= 0 ? 0 :
      count_odds(n, a, idx-1) + (a[idx-1] % 2 == 1 ? 1 : 0);
*/

/*@ lemma loop_invariant_maintained:
      \forall integer n; \forall int32_t *a; \forall integer i, count;
      is_valid_array(n, a) && 0 <= i <= n && count >= 0 && count <= i &&
      count == count_odds(n, a, i) ==>
      (i < n ==> (a[i] % 2 == 1 ==> count+1 <= i+1) && (a[i] % 2 == 0 ==> count <= i+1));
*/

/*@ requires n >= 1 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
    ensures \result >= -1 && \result <= n;
    assigns \nothing;
*/
int32_t func(uint32_t n, int32_t *a) {
    uint32_t i = 0;
    int32_t count = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant count == count_odds(n, a, i);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert count <= i;
        if (a[i] % 2 == 1) {
            count += 1;
        }
        i += 1;
        //@ assert count <= i;
    }
    
    if (count == 0) {
        return -1;
    } else {
        return count;
    }
}
