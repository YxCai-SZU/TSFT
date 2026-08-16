#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == (((a) + (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t avg;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    sum = a + b;
    //@ assert sum == a + b;
    avg = (sum + 1) / 2;
    //@ assert avg == (((a) + (b) + 1) / 2);
    return avg;
}
