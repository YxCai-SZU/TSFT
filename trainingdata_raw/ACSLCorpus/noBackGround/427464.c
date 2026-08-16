#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result == 6 - (a + b);
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b)
{
    // Variable declarations at scope top
    uint64_t opposite_color;
    int64_t result;

    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    
    opposite_color = 6 - a - b;
    
    //@ assert opposite_color == 6 - (a + b);
    
    result = (int64_t)opposite_color;
    return result;
}
