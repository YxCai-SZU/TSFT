#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer compute_x(integer n, integer count) = count * 5;
    logic integer compute_y(integer n, integer rem) = rem;

    lemma count_bounds: \forall integer n, count;
        is_valid_n(n) && 0 <= count && count <= n / 100 ==> 
        compute_x(n, count) >= 0;

    lemma rem_bounds: \forall integer n, rem;
        is_valid_n(n) && 0 <= rem && rem <= n ==> 
        compute_y(n, rem) >= 0;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 0 || \result == 1;
    ensures \result == 0 ==> n % 100 <= 5 * (n / 100);
    ensures \result == 1 ==> n % 100 > 5 * (n / 100);
*/
int32_t func(uint32_t n)
{
    int32_t res = 0;
    uint32_t tmp_n = n;
    uint32_t count = 0;
    uint32_t x = 0;
    uint32_t rem = n;
    uint32_t y = 0;

    // First loop: count hundreds
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= count <= n / 100;
        loop invariant tmp_n == n - 100 * count;
        loop invariant 0 <= tmp_n <= n;
        loop assigns tmp_n, count;
        loop variant tmp_n;
    */
    while (tmp_n >= 100)
    {
        //@ assert tmp_n >= 100;
        tmp_n -= 100;
        count += 1;
    }
    x = count * 5;

    // Second loop: compute remainder
    /*@
        loop invariant 1 <= n <= 100000;
        loop invariant 0 <= rem <= n;
        loop invariant rem == n - 100 * (n / 100 - rem / 100);
        loop assigns rem;
        loop variant rem;
    */
    while (rem >= 100)
    {
        //@ assert rem >= 100;
        rem -= 100;
    }
    y = rem;

    //@ assert y == n % 100;
    //@ assert x == 5 * (n / 100);
    
    if (y > x)
    {
        res = 1;
    }
    
    return res;
}
