#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (\let n = (x) / 100;
        \let remained = (x) % 100;
        \let a = remained / 5;
        \let b = remained % 5;
        \let total = n + a;
        total + ((b == 0 || b == 1 || b == 2 || b == 3) ? 1 : 0)) <= 100000;
    ensures \result == 0 ==> (\let n = (x) / 100;
        \let remained = (x) % 100;
        \let a = remained / 5;
        \let b = remained % 5;
        \let total = n + a;
        total + ((b == 0 || b == 1 || b == 2 || b == 3) ? 1 : 0)) > 100000;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    uint32_t remained;
    uint32_t a;
    uint32_t b;
    uint32_t total;

    n = x / 100;
    remained = x % 100;
    a = remained / 5;
    b = remained % 5;
    total = n + a;

    //@ assert total == n + a;

    if (b == 0 || b == 1 || b == 2 || b == 3)
    {
        total = total + 1;
        //@ assert total == n + a + 1;
    }
    else
    {
        //@ assert total == n + a;
    }

    //@ assert total == (\let n = (x) / 100;         \let remained = (x) % 100;         \let a = remained / 5;         \let b = remained % 5;         \let total = n + a;         total + ((b == 0 || b == 1 || b == 2 || b == 3) ? 1 : 0));

    if (total <= 100000)
    {
        //@ assert total <= 100000;
        return 1;
    }
    else
    {
        //@ assert total > 100000;
        return 0;
    }
}
