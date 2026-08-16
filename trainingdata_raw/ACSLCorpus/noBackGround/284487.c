#include <stdint.h>
/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    requires ((int64_t)(a) * (int64_t)(b) <= INT32_MAX &&
        (int64_t)(a) * (int64_t)(b) >= INT32_MIN);
    ensures \result == (int32_t)(a * b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert ((int64_t)(a) * (int64_t)(b) <= INT32_MAX &&         (int64_t)(a) * (int64_t)(b) >= INT32_MIN);
    //@ assert (int64_t)a * (int64_t)b <= 10000 * 10000;
    
    uint32_t ans = a * b;
    return (int32_t)ans;
}
