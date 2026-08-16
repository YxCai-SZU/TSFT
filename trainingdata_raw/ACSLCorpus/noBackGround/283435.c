#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == -1 || \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t s;
    uint32_t l;
    int32_t result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    //@ assert ((a) + (b)) <= 20000;
    s = a + b;

    //@ assert ((c) + (d)) <= 20000;
    l = c + d;

    result = -1;

    if (s < l)
    {
        result = 1;
    }
    else if (s == l)
    {
        result = 0;
    }

    if (b > c && b > d && a < c && a < d)
    {
        result = -1;
    }
    else if (d > a && d > b && c < a && c < b)
    {
        result = 1;
    }
    else if ((a == c && b == d) || (a == d && b == c))
    {
        result = 0;
    }

    //@ assert result == -1 || result == 0 || result == 1;
    return result;
}
