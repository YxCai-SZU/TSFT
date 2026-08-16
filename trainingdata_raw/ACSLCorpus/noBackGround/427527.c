#include <stdint.h>

/*@
    requires (0 <= (a) < 24) && (0 <= (b) < 24);
    ensures \result == ((a) + (b) >= 24 ? (a) + (b) - 24 : (a) + (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;

    sum = a + b;

    if (sum < 24)
    {
        //@ assert sum == a + b;
        return sum;
    }
    else
    {
        //@ assert sum == a + b;
        return sum - 24;
    }
}
