#include <stdint.h>

/*@ predicate bounds(integer n) = 3 <= n <= 100; */
/*@ logic integer compute(integer n) = (n - 2) * 180; */

/*@ lemma arithmetic_bounds:
      \forall integer n; bounds(n) ==> 1 <= n - 2 <= 98; */

/*@ lemma product_bounds:
      \forall integer n; bounds(n) ==> 180 <= compute(n) <= 17640; */

/*@ requires bounds(n);
    ensures \result == compute(n);
    assigns \nothing;
 */
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t ans;
    
    //@ assert 3 <= n && n <= 100;
    //@ assert 1 <= n - 2 && n - 2 <= 98;
    //@ assert 180 <= (n - 2) * 180 && (n - 2) * 180 <= 17640;
    
    ans = (int32_t)((n - 2) * 180);
    return ans;
}
