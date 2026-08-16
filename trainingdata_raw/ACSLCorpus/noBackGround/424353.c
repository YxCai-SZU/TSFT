#include <stddef.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + ((y) / 2));
    assigns \nothing;
*/
size_t func(size_t x, size_t y)
{
    // Variable declarations at scope top
    size_t result;

    //@ assert (1 <= (x) <= 100 &&         1 <= (y) <= 100 &&         (y) % 2 == 0);
    //@ assert ((x) + ((y) / 2)) == x + (y / 2);
    
    result = x + (y / 2);
    
    //@ assert result == ((x) + ((y) / 2));
    return result;
}
