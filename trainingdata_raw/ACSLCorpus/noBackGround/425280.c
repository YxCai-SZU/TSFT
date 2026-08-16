#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t p)
{
    uint64_t sum;
    //@ assert (0 <= (a) <= 100 && 0 <= (p) <= 100);
    sum = a * 3 + p;
    //@ assert sum == a * 3 + p;
    return sum / 2;
}
