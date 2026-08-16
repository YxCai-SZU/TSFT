#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a;
    ensures \result >= 0;
    ensures \result == a - b * 2 || \result == 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert a > b * 2 || a <= b * 2;

    if (a > b * 2)
    {
        result = a - b * 2;
    }
    else
    {
        result = 0;
    }

    //@ assert result <= a;
    //@ assert result >= 0;
    //@ assert result == a - b * 2 || result == 0;

    return result;
}
