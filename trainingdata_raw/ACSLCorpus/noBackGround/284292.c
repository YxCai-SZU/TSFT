#include <stdbool.h>
#include <stdint.h>

/*@
    requires (0 <= (a) <= 0xffffffff) && (0 <= (b) <= 0xffffffff);
    ensures \result == ((a & b) == a);
    assigns \nothing;
*/
bool func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    bool result;

    //@ assert (0 <= (a) <= 0xffffffff);
    //@ assert (0 <= (b) <= 0xffffffff);
    
    result = ((a & b) == a);
    return result;
}
