#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result >= 0;
    ensures \result == (800 * (n) - 200 * ((n) / 15));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t result;
    int32_t temp1;
    int32_t temp2;

    //@ assert 800 * n >= 0;
    temp1 = 800 * (int32_t)n;

    //@ assert 200 * (n / 15) >= 0;
    temp2 = 200 * (int32_t)(n / 15);

    //@ assert temp1 - temp2 >= 0;
    result = temp1 - temp2;

    return result;
}
