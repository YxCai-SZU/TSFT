#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100 &&
        1 <= (y) && (y) <= 100);
    ensures \result == (((x) - 1) * ((y) - 1));
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    //@ assert (1 <= (x) && (x) <= 100 &&         1 <= (y) && (y) <= 100);
    //@ assert x - 1 >= 0;
    //@ assert y - 1 >= 0;
    //@ assert (x - 1) * (y - 1) <= 99 * 99;
    
    return (x - 1) * (y - 1);
}
