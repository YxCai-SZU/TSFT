#include <stddef.h>

/*@
    requires (1 <= (n) <= 1000000);
    ensures \result == (((n) - 1) / 2 + 1);
    assigns \nothing;
*/
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t result;
    
    //@ assert n > 0 && n <= 1000000;
    
    //@ assert (n - 1) / 2 <= 499999;
    
    //@ assert (n - 1) / 2 + 1 <= 500000;
    
    result = (n - 1) / 2 + 1;
    
    //@ assert result == (((n) - 1) / 2 + 1);
    
    return result;
}
