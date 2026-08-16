#include <stddef.h>


size_t func(size_t a, size_t b)
{
    size_t res;
    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    res = 6 - a - b;
    //@ assert res == (6 - (a) - (b));
    //@ assert res >= 1 && res <= 3;
    return res;
}
