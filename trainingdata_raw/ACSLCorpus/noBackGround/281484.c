#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000 &&
        (a) <= (b) &&
        (c) <= (d));
    ensures \result >= 0;
    ensures \result <= d - c;
    ensures \result <= b - a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t begin;
    uint32_t end;
    uint32_t result;

    begin = a > c ? a : c;
    end = b < d ? b : d;

    if (begin > end)
    {
        result = 0;
        //@ assert result == 0;
        return result;
    }

    //@ assert begin >= a && begin >= c;
    //@ assert end <= b && end <= d;
    //@ assert begin <= end;
    //@ assert end - begin <= d - c;
    //@ assert end - begin <= b - a;

    result = end - begin;
    //@ assert result >= 0;
    return result;
}
