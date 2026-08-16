#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000;

    logic integer half_value(integer n, integer half) = n - 2 * half;

    lemma half_division: \forall integer n, half;
        is_valid_n(n) && 0 <= half <= n/2 ==> half_value(n, half) >= 0;

    lemma result_correct: \forall integer n, half, temp_n;
        is_valid_n(n) && 0 <= half <= n/2 && temp_n == half_value(n, half) && temp_n <= 1 ==>
        (temp_n == 1 ? half + 1 : half) == n/2 + n%2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == n/2 + n%2;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t half = 0;
    uint32_t temp_n = n;
    uint32_t res = 0;

    /*@
        loop invariant is_valid_n(n);
        loop invariant 0 <= half <= n/2;
        loop invariant temp_n == n - 2 * half;
        loop invariant temp_n >= 0;
        loop assigns half, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 2)
    {
        //@ assert temp_n >= 2;
        temp_n -= 2;
        half += 1;
        //@ assert half <= n/2;
    }

    //@ assert temp_n == n % 2;
    //@ assert half == n / 2;

    if (temp_n == 1)
    {
        res = half + 1;
        //@ assert res == n/2 + 1;
    }
    else
    {
        res = half;
        //@ assert res == n/2;
    }

    //@ assert res == n/2 + n%2;
    return res;
}
