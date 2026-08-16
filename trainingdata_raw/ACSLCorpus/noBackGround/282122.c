#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result >= 0;
    ensures \result <= 3;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) == (b) || (b) == (c) || (c) == (a)) ? 2 : 3);
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    if (a == b && b == c)
    {
        //@ assert a == b && b == c;
        result = 1;
    }
    else if (a == b || b == c || c == a)
    {
        //@ assert a == b || b == c || c == a;
        result = 2;
    }
    else
    {
        //@ assert a != b && b != c && c != a;
        result = 3;
    }

    //@ assert result >= 0;
    //@ assert result <= 3;
    return result;
}
