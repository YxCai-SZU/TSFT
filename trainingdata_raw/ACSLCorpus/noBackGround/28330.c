#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures ((\result) == ((a) * (b) + 1) || (\result) == -1);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t ans;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert a * b <= 10000;
    
    ans = a * b;
    
    if (ans < 0) {
        return -1;
    }
    return (int32_t)(ans + 1);
}
