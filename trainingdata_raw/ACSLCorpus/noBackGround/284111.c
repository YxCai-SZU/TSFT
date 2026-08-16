#include <stdbool.h>
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
    size_t ans;

    //@ assert x <= 100;
    //@ assert y <= 100;
    //@ assert y / 2 <= 50;
    //@ assert x + (y / 2) <= 150;

    ans = x + (y / 2);
    
    return ans;
}
