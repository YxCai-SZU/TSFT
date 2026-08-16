#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    ensures \result <= 200;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    // Variable declarations at scope top
    uint32_t temp1;
    uint32_t temp2;
    uint32_t result;

    //@ assert a <= 100;
    temp1 = a * 3;
    //@ assert temp1 <= 300;
    temp2 = temp1 + p;
    //@ assert temp2 <= 400;
    result = temp2 / 2;
    //@ assert result == (((a) * 3 + (p)) / 2);
    return result;
}
