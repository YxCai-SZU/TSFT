#include <stdbool.h>
#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n <= 100;
    predicate is_valid_m(integer m) = 1 <= m <= 100;
    predicate is_valid_x(integer x, integer n) = 1 <= x <= n - 1;
    
    predicate an_len_eq(uint32_t *an, integer n) = \valid(an + (0..n-1));
    predicate am_len_eq(uint32_t *am, integer m) = \valid(am + (0..m-1));
    
    predicate an_range(uint32_t *an, integer n) = 
        \forall integer i; 0 <= i < n ==> 1 <= an[i] <= n;
    predicate am_range(uint32_t *am, integer m) = 
        \forall integer i; 0 <= i < m ==> 1 <= am[i] <= m;
    
    predicate an_sorted(uint32_t *an, integer n) = 
        \forall integer i; 0 <= i < n-1 ==> an[i] < an[i+1];
    predicate am_sorted(uint32_t *am, integer m) = 
        \forall integer i; 0 <= i < m-1 ==> am[i] < am[i+1];
*/

/*@
    requires 
        is_valid_n(n) && is_valid_m(m) && is_valid_x(x, n) &&
        an_len_eq(an, n) && am_len_eq(am, m) &&
        an_range(an, n) && am_range(am, m) &&
        an_sorted(an, n) && am_sorted(am, m);
    ensures 
        0 <= \result <= m;
*/
uint32_t func(uint32_t n, uint32_t m, uint32_t x, uint32_t *an, uint32_t *am)
{
    uint32_t ans_n = 0;
    uint32_t i = 0;
    
    /*@
        loop invariant 0 <= i <= m;
        loop invariant 0 <= ans_n <= i;
        loop assigns i, ans_n;
        loop variant m - i;
    */
    while (i < m)
    {
        uint32_t a = am[i];
        //@ assert 1 <= a <= m;
        if (a >= x)
        {
            ans_n += 1;
        }
        i += 1;
    }
    
    uint32_t ans_0 = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= ans_0 <= i;
        loop assigns i, ans_0;
        loop variant n - i;
    */
    while (i < n)
    {
        uint32_t a = an[i];
        //@ assert 1 <= a <= n;
        if (a <= x)
        {
            ans_0 += 1;
        }
        i += 1;
    }
    
    uint32_t ans = (ans_n < ans_0) ? ans_n : ans_0;
    //@ assert 0 <= ans <= m;
    return ans;
}
