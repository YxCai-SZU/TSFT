#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (((n) + 999) / 1000 * 1000);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t x;
    size_t y;
    size_t res;

    x = n / 1000;
    y = n % 1000;

    if (y == 0)
    {
        res = x * 1000;
        //@ assert res == (((n) + 999) / 1000 * 1000);
        return res;
    }
    else
    {
        //@ assert x < 10;
        res = (x + 1) * 1000;
        //@ assert res == (((n) + 999) / 1000 * 1000);
        return res;
    }
}
