#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (((n) / 100 * 100 + 99) - (n));
    assigns \nothing;
*/
size_t func(size_t n)
{
    // Variable declarations at scope top
    size_t result;
    
    //@ assert (1 <= (n) <= 10000);
    
    //@ assert n / 100 * 100 + 99 >= n;
    
    result = (n / 100 * 100 + 99) - n;
    
    //@ assert result == (((n) / 100 * 100 + 99) - (n));
    
    return result;
}
