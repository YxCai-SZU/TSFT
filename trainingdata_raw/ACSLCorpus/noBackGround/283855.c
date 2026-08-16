#include <stdint.h>

/*@
    requires (0 <= (r) <= 4500 && 0 <= (g) <= 4500);
    ensures \result == ((g) * 2 - (r));
    assigns \nothing;
*/
int64_t func(int64_t r, int64_t g)
{
    // Variable declarations at scope top
    int64_t res;
    
    //@ assert g * 2 - r == g * 2 - r;
    
    res = g * 2 - r;
    return res;
}
