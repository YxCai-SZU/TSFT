#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == a + b || \result == b + c || \result == c + a;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t min1;
    int64_t min2;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a + b < b + c)
    {
        min1 = a + b;
    }
    else
    {
        min1 = b + c;
    }

    //@ assert min1 == a + b || min1 == b + c;

    if (min1 < c + a)
    {
        min2 = min1;
    }
    else
    {
        min2 = c + a;
    }

    //@ assert min2 == a + b || min2 == b + c || min2 == c + a;

    return min2;
}
