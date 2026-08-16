#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = 3 <= x <= 200;
    predicate result_in_range(integer r) = 3 <= r <= 200;
*/

/*@
    requires is_valid_range(x);
    ensures result_in_range(\result);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t result;

    n = x / 3;
    result = 0;

    /*@
        loop invariant 0 <= n <= x/3;
        loop invariant result == 3 * ((x/3) - n);
        loop invariant is_valid_range(x);
        loop assigns n, result;
        loop variant n;
    */
    while (n > 0)
    {
        //@ assert result == 3 * ((x/3) - n);
        result += 3;
        n -= 1;
    }

    //@ assert result_in_range(result);
    return result;
}
