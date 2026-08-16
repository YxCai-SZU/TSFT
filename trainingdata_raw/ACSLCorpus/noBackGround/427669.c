#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000000000000000);
    ensures \result <= (2 * ((x) / 11) + 2);
    ensures \result >= (2 * ((x) / 11));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t n;
    uint64_t h;
    uint64_t result;

    n = x / 11;
    h = x % 11;

    if (h == 0)
    {
        result = 2 * n;
        //@ assert result == (2 * ((x) / 11));
        return result;
    }
    else if (h < 7)
    {
        //@ assert h < 7;
        result = 2 * n + 1;
        //@ assert result <= (2 * ((x) / 11) + 2);
        return result;
    }
    else
    {
        //@ assert h >= 7;
        result = 2 * n + 2;
        //@ assert result == (2 * ((x) / 11) + 2);
        return result;
    }
}
