#include <stdint.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int func(uint64_t x)
{
    uint64_t n;
    uint64_t remained;
    uint64_t a;
    uint64_t b;
    uint64_t total;

    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;
    total = n + a;

    if (b > 0)
    {
        total = total + 1;
    }

    //@ assert total >= n + a;
    //@ assert total <= n + a + 1;

    if (total > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
