#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures ((a) < 10 && (b) < 10) ==> \result == (int)(a * b);
    ensures !((a) < 10 && (b) < 10) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Declare all variables at scope top
    int32_t result;

    if (a < 10 && b < 10)
    {
        //@ assert a > 0 && a <= 10;
        //@ assert b > 0 && b <= 10;
        //@ assert a * b <= 100;
        result = (int32_t)(a * b);
    }
    else
    {
        //@ assert a >= 10 || b >= 10;
        result = -1;
    }

    return result;
}
