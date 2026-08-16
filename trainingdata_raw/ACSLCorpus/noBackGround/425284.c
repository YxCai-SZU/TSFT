#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result < 1000;
    ensures \result >= 0;
    ensures \result == (((n) % 1000 == 0) ? 0 : (1000 - ((n) % 1000)));
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t r;
    size_t result;
    
    //@ assert (1 <= (n) && (n) <= 10000);
    
    if (n % 1000 == 0) {
        result = 0;
        //@ assert result == (((n) % 1000 == 0) ? 0 : (1000 - ((n) % 1000)));
        return result;
    } else {
        r = n % 1000;
        //@ assert r < 1000;
        //@ assert r >= 0;
        result = 1000 - r;
        //@ assert result == (((n) % 1000 == 0) ? 0 : (1000 - ((n) % 1000)));
        return result;
    }
}
