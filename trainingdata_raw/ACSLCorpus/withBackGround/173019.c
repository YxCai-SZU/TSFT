#include <stdint.h>

/*@
    predicate valid_range(integer n) = 3 <= n <= 100;
    
    logic integer poly_sum(integer idx, integer n) = (idx - 3) * 180;
    
    lemma sum_formula:
        \forall integer idx, n;
        valid_range(n) && 3 <= idx <= n + 1 ==>
        poly_sum(idx + 1, n) == poly_sum(idx, n) + 180;
*/

/*@
    requires valid_range(n);
    ensures \result == (n - 2) * 180;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t sum = 0;
    uint32_t idx = 3;
    
    /*@
        loop invariant 3 <= idx <= n + 1;
        loop invariant sum == poly_sum(idx, n);
        loop invariant valid_range(n);
        loop assigns idx, sum;
        loop variant n - idx;
    */
    while (idx <= n)
    {
        //@ assert idx <= n;
        idx = idx + 1;
        sum = sum + 180;
        //@ assert sum == poly_sum(idx, n);
    }
    
    //@ assert idx == n + 1;
    //@ assert sum == poly_sum(n + 1, n);
    //@ assert sum == (n - 2) * 180;
    
    return sum;
}
