#include <stdbool.h>
#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 0 && \result <= 3;
    ensures \result == 3 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && a != c) || (a == c && a != b) || (b == c && b != a));
    ensures \result == 0 ==> (a != b && b != c && a != c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    if (a == b && b == c)
    {
        result = 3;
        //@ assert result == 3 && a == b && b == c;
    }
    else if (a == b || a == c || b == c)
    {
        result = 2;
        //@ assert result == 2 && (a == b || a == c || b == c);
    }
    else
    {
        result = 0;
        //@ assert a != b && b != c && a != c;
    }

    //@ assert result >= 0 && result <= 3;
    return result;
}
