#include <stdint.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20);
    ensures (a <= 9 && b <= 9 ==> \result == a * b);
    ensures (a > 9 || b > 9 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t result;

    if (a > 9 || b > 9)
    {
        result = -1;
    }
    else
    {
        //@ assert a >= 1 && a <= 9;
        //@ assert b >= 1 && b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    }

    return result;
}
