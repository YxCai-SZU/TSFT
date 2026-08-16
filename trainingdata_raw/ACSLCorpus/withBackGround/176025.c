#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer div100(integer n) = n / 100;
    logic integer mod100(integer n) = n % 100;

    lemma division_property:
        \forall integer n, x, y;
            is_valid_n(n) && x == div100(n) && y == mod100(n) ==> n == 100 * x + y;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> mod100(n) <= 5 * div100(n);
    ensures \result == 0 ==> mod100(n) > 5 * div100(n);
*/
int32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    int32_t result;

    x = n / 100;
    y = n % 100;

    //@ assert n == 100 * x + y;
    //@ assert x <= 1000;
    //@ assert y <= 100;

    if (y <= 5 * x)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    return result;
}
