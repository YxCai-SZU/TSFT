#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer total_x(integer n) = 800 * n;
    logic integer total_y(integer n) = (n / 15) * 200;
    logic integer expected_result(integer n) = total_x(n) - total_y(n);

    lemma overflow_bound: \forall integer n; valid_n(n) ==> total_x(n) <= 80000;
    lemma division_property: \forall integer n; valid_n(n) ==> n/15 * 15 <= n < (n/15 + 1) * 15;
*/

/*@
    requires valid_n(n);
    ensures \result == expected_result(n);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    int32_t x;
    int32_t y;
    int32_t ans;
    uint32_t quotient = 0;
    uint32_t remainder = n;

    //@ assert valid_n(n);
    
    // Overflow check
    //@ assert total_x(n) <= 80000;
    x = 800 * (int32_t)n;

    /*@
        loop invariant 0 <= quotient <= n/15;
        loop invariant remainder == n - quotient * 15;
        loop invariant remainder >= 0;
        loop invariant valid_n(n);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        quotient += 1;
        remainder -= 15;
    }

    //@ assert quotient == n/15;
    //@ assert remainder == n % 15;
    
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == expected_result(n);
    return ans;
}
