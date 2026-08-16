#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 &&
        1 <= (b) <= 3 &&
        (a) != (b));
    ensures \result == (6 - (a) - (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert (1 <= (a) <= 3 &&         1 <= (b) <= 3 &&         (a) != (b));
    
    //@ assert (6 - (a) - (b)) <= 4;
    //@ assert (6 - (a) - (b)) >= 0;
    
    //@ assert (6 - (a) - (b)) == (6 - (a) - (b));
    
    return 6 - a - b;
}
