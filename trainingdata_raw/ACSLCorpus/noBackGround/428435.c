#include <stddef.h>

/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= c <= 50;
    ensures \result >= 0;
    ensures \result <= 3;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t max_ab;
    size_t max;
    size_t result = 0;

    //@ assert (0 <= (a) <= 50);
    //@ assert (0 <= (b) <= 50);
    //@ assert (0 <= (c) <= 50);

    if (a > b)
    {
        max_ab = a;
    }
    else
    {
        max_ab = b;
    }

    if (max_ab > c)
    {
        max = max_ab;
    }
    else
    {
        max = c;
    }

    //@ assert max == (((a) >= (b) && (a) >= (c)) ? (a) : (((b) >= (a) && (b) >= (c)) ? (b) : (c)));

    if (max == a)
    {
        result += 1;
    }
    if (max == b)
    {
        result += 1;
    }
    if (max == c)
    {
        result += 1;
    }

    //@ assert result >= 1 && result <= 3;
    //@ assert result >= 0 && result <= 3;

    return result;
}
