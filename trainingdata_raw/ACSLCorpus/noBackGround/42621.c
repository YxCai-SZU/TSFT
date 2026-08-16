#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert a * b <= 10000;
    return a * b;
}
