#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures -1 <= \result <= 3;
    ensures \result == ((a) == (b) && (b) == (c) ? 1 :
        (a) == (b) || (a) == (c) || (b) == (c) ? 0 :
        -1);
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t i;
    int32_t result;

    if (a == b && b == c)
    {
        result = 1;
        //@ assert result == 1;
    }
    else if (a == b || a == c || b == c)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        i = 0;
        /*@
            loop invariant 0 <= i <= 10;
            loop invariant a != b || b != c || a != c;
            loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
            loop assigns i;
        */
        while (i < 10)
        {
            i = i + 1;
        }
        result = -1;
        //@ assert result == -1;
    }

    //@ assert -1 <= result <= 3;
    return result;
}
