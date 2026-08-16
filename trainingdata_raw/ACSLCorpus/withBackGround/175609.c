/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer n_div_15(integer n) = n / 15;
    
    lemma division_property:
        \forall integer n, d;
        n >= 0 && d > 0 ==>
        n - d * (n / d) >= 0 &&
        n - d * (n / d) < d;
*/

#include <stdint.h>

/*@
    requires is_valid_n(n);
    ensures \result >= 800 * (int32_t)n - 200 * (int32_t)(n / 15);
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t res;
    uint32_t n_div_15;
    uint32_t temp_n;
    
    //@ assert is_valid_n(n);
    res = 800 * (int32_t)n;
    n_div_15 = 0;
    temp_n = n;
    
    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= temp_n <= n;
        loop invariant n_div_15 >= 0;
        loop invariant n_div_15 <= n / 15;
        loop invariant temp_n == n - 15 * n_div_15;
        loop assigns temp_n, n_div_15;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n = temp_n - 15;
        n_div_15 = n_div_15 + 1;
        //@ assert temp_n == n - 15 * n_div_15;
    }
    
    //@ assert n_div_15 == n / 15;
    res = res - 200 * (int32_t)n_div_15;
    //@ assert res >= 800 * (int32_t)n - 200 * (int32_t)(n / 15);
    return res;
}
