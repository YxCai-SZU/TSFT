#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100);
    ensures \result == ((a) * 3 + (b) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_val;
    uint32_t b_val;
    uint32_t result;

    //@ assert a * 3 <= 300;
    a_val = a * 3;

    //@ assert b / 2 <= 50;
    b_val = b / 2;

    result = a_val + b_val;
    //@ assert result == ((a) * 3 + (b) / 2);
    return result;
}
