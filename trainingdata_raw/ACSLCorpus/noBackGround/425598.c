#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 3 &&
        1 <= (b) && (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    //@ assert (1 <= (a) && (a) <= 3 &&         1 <= (b) && (b) <= 3 &&         (a) != (b));
    
    //@ assert 2 <= a + b && a + b <= 6;
    
    //@ assert 1 <= 6 - a - b && 6 - a - b <= 3;
    
    size_t ans = 6 - a - b;
    
    //@ assert ans == (6 - (a) - (b));
    
    return ans;
}
