#include <stdint.h>

/*@
    requires (0 <= (a) <= 100) && (2 <= (b) <= 1000 && (b) % 2 == 0);
    ensures \result == (((a) * 3 + (b)) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a * 3 <= 300;
    //@ assert a * 3 + b <= 1300;
    return (a * 3 + b) / 2;
}
