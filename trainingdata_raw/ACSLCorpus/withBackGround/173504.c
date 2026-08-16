#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;

    logic integer compute_result(integer n) = 800 * n - 200 * (n / 15);

    lemma overflow_bound_x:
        \forall integer n; valid_n(n) ==> 800 * n <= 800 * 100;

    lemma overflow_bound_y:
        \forall integer n, integer q; valid_n(n) && q <= n / 15 ==> 200 * q <= 200 * 100;
*/

/*@
    requires valid_n(n);
    ensures \result == compute_result(n);
*/
int32_t func(uint32_t n)
{
    // Variable declarations
    int32_t x;
    uint32_t quotient = 0;
    uint32_t remainder = n;
    uint32_t divisor = 15;
    int32_t y;
    int32_t ans;

    //@ assert valid_n(n);
    //@ assert divisor == 15;

    // Verify no overflow in 800 * n
    //@ assert 800 * n <= 800 * 100;

    x = 800 * (int32_t)n;

    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant divisor == 15;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }

    // Verify no overflow in 200 * quotient
    //@ assert 200 * quotient <= 200 * 100;

    y = 200 * (int32_t)quotient;
    ans = x - y;

    // Final verification
    //@ assert ans == 800 * n - 200 * quotient;
    return ans;
}
