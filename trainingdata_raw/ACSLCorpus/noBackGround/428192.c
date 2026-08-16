#include <stdint.h>

/*@
    requires (2 <= (x) && (x) <= 100 &&
        2 <= (y) && (y) <= 100);
    ensures \result == (((x) - 1) * ((y) - 1));
    assigns \nothing;
*/
int64_t func(int64_t x, int64_t y)
{
    int64_t result;
    
    //@ assert 1 <= x - 1 && x - 1 <= 99;
    //@ assert 1 <= y - 1 && y - 1 <= 99;
    //@ assert (x - 1) * (y - 1) <= 99 * 99;
    
    result = (x - 1) * (y - 1);
    
    //@ assert result == (((x) - 1) * ((y) - 1));
    return result;
}
