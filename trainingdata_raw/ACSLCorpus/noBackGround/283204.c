#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    if (n < 100) {
        //@ assert 1 <= n && n <= 99;
        //@ assert n * n <= 99 * 99;
        result = n * n;
    } else {
        //@ assert 100 <= n && n <= 100;
        //@ assert n * n <= 100 * 100;
        result = n * n;
    }
    
    //@ assert result == ((n) * (n));
    return result;
}
