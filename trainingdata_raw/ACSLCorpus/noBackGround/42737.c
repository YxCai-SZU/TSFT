#include <stddef.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= (n) &&
        1 <= (y) <= (n) &&
        (x) < (y));
    ensures \result == ((n) - 1 + (n) - ((y) - (x) - 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t x, size_t y)
{
    size_t ret;

    //@ assert (1 <= (n) <= 100 &&         1 <= (x) <= (n) &&         1 <= (y) <= (n) &&         (x) < (y));
    
    ret = n - 1 + n - (y - x - 1);
    
    //@ assert ret == ((n) - 1 + (n) - ((y) - (x) - 1));
    
    return ret;
}
