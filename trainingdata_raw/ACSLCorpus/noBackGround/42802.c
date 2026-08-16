#include <stddef.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) + (b) + (c) + (d));
    ensures \result >= a;
    ensures \result >= b;
    ensures \result >= c;
    ensures \result >= d;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t train;
    size_t bus;
    size_t res;

    train = a + b;
    bus = c + d;
    res = train + bus;

    //@ assert res == ((a) + (b) + (c) + (d));

    return res;
}
