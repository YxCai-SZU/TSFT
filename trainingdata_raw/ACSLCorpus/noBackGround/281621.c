#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures \result == 1 ==> (n % 100) * 21 / 100 == n;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t a;
    uint32_t b;
    uint32_t x;
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 100000);
    //@ assert n / 100 <= 1000;
    //@ assert n % 100 <= 100;
    //@ assert (n % 100) * 21 <= 100 * 21;

    a = n / 100;
    b = n % 100;
    x = (b + (100 - b) % 21) % 21;

    if ((a + (100 - b) / 21) * 100 + x == n)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert result == 0 || result == 1;
    return result;
}
