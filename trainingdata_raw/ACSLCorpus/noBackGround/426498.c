#include <stddef.h>

/*@
    requires (2 <= (m) <= (n) <= 100000);
    ensures \result == (((n) - 2) / ((m) - 1) + 1);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at top of scope
    size_t res;
    
    //@ assert n - 2 >= 0;
    //@ assert m - 1 >= 1;
    //@ assert (n - 2) / (m - 1) <= 100000;
    
    res = (n - 2) / (m - 1) + 1;
    return res;
}
