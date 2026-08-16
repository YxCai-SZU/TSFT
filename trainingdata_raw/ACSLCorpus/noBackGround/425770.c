#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result == ((n) - (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    //@ assert n - m >= 0;
    //@ assert n - m <= 100;
    result = (int32_t)(n - m);
    return result;
}
