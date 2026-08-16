#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    requires (1 <= (b) && (b) <= 10);
    requires (1 <= (c) && (c) <= 10);
    ensures \result == ((a) * (b) * (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Local variable declarations
    uint32_t result;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert (1 <= (b) && (b) <= 10);
    //@ assert (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) ==> a * b <= 100;
    //@ assert (1 <= (c) && (c) <= 10);
    //@ assert (1 <= (a) && (a) <= 10) && (1 <= (b) && (b) <= 10) && (1 <= (c) && (c) <= 10) ==> a * b * c <= 1000;

    result = a * b * c;
    //@ assert result == ((a) * (b) * (c));
    return result;
}
