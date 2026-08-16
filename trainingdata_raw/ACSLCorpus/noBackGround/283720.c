#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t m;
    uint32_t res;

    n = x / 500;
    m = (x % 500) / 5;
    res = n * 1000 + m * 5;

    //@ assert n == x / 500;
    //@ assert m == (x % 500) / 5;
    //@ assert res == n * 1000 + m * 5;
    //@ assert res == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return res;
}
