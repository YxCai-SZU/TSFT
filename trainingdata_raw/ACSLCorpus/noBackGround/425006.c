#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result <= b / a;
    ensures \result <= c;
    ensures \result == b / a || \result == c;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t pieces;
    uint32_t result;

    pieces = b / a;

    //@ assert pieces == b / a;

    if (pieces <= c)
    {
        result = pieces;
        //@ assert result == b / a;
        //@ assert result <= c;
    }
    else
    {
        //@ assert pieces > c;
        //@ assert pieces <= 100;
        //@ assert c <= 100;
        //@ assert pieces >= c;
        result = c;
        //@ assert result <= b / a;
        //@ assert result == c;
    }

    //@ assert result <= b / a;
    //@ assert result <= c;
    //@ assert result == b / a || result == c;
    return result;
}
