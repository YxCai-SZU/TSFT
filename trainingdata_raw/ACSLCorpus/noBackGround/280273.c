#include <stdint.h>

/*@
    requires 1 <= n <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> n % 100 <= 5 * (n / 100);
    ensures \result == 0 ==> n % 100 > 5 * (n / 100);
*/
uint32_t func(uint32_t n)
{
    uint32_t q;
    uint32_t r;
    uint32_t result;

    q = n / 100;
    r = n % 100;

    if (r <= 5 * q)
    {
        //@ assert n % 100 <= 5 * (n / 100);
        result = 1;
    }
    else
    {
        //@ assert n % 100 > 5 * (n / 100);
        result = 0;
    }

    return result;
}
