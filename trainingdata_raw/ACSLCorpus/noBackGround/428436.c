#include <stdint.h>

/*@
    requires (101 <= (x) <= 100000000000000000);
    ensures \result > 0;
    ensures \result == 100 + (x - 101) / 100 || \result == 100 + (x - 101) / 100 + 1;
*/
uint64_t func(uint64_t x)
{
    uint64_t res_base;
    uint64_t extra;
    uint64_t quotient;
    uint64_t res;

    res_base = 100;
    extra = x - 101;
    quotient = 0;

    /*@
        loop invariant 101 <= x <= 100000000000000000;
        loop invariant res_base == 100;
        loop invariant extra >= 0;
        loop invariant quotient >= 0;
        loop invariant x - 101 == extra + 100 * quotient;
        loop assigns extra, quotient;
        loop variant extra;
    */
    while (extra >= 100)
    {
        //@ assert extra >= 100;
        extra -= 100;
        quotient += 1;
    }

    res = res_base + quotient;

    if (extra > 0)
    {
        //@ assert extra > 0;
        return res + 1;
    }
    else
    {
        //@ assert extra == 0;
        return res;
    }
}
