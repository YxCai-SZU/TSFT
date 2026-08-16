#include <stdint.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (((r)) * ((r))));
    assigns \nothing;
*/
int64_t func(uint64_t r)
{
    int64_t result;
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert ((r) * (r)) <= 10000;
    
    result = 3 * ((int64_t)r * (int64_t)r);
    
    //@ assert result == (3 * (((r)) * ((r))));
    return result;
}
