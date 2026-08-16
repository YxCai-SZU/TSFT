#include <stdint.h>

/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures ((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == a * b;
    ensures !((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    int32_t result;

    if (a <= 9 && b <= 9)
    {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert a * b <= 81;
        result = (int32_t)(a * b);
    }
    else
    {
        result = -1;
    }

    return result;
}
