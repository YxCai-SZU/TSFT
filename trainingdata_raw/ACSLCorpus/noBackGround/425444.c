#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100);
    assigns \nothing;
    ensures \result >= 0 && \result <= 3;
    ensures ((a) == (b) && (b) == (c) ==> (\result) == 1);
    ensures (((a) == (b) && (b) != (c) || (a) == (c) && (b) != (c) || (a) != (b) && (b) == (c)) ==> (\result) == 2);
    ensures (((a) != (b) && (b) != (c) && (a) != (c)) ==> (\result) == 3);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert ((a) == (b) && (b) == (c) ==> (result) == 1);
    }
    else if (a != b && b != c && a != c)
    {
        result = 3;
        //@ assert (((a) != (b) && (b) != (c) && (a) != (c)) ==> (result) == 3);
    }
    else
    {
        //@ assert a == b && b != c || a == c && b != c || a != b && b == c;
        result = 2;
        //@ assert (((a) == (b) && (b) != (c) || (a) == (c) && (b) != (c) || (a) != (b) && (b) == (c)) ==> (result) == 2);
    }

    //@ assert result >= 0 && result <= 3;
    return result;
}
