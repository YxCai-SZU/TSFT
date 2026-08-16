#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == (((n) / 2) - ((n) / 2) / 2);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res;
    
    //@ assert (1 <= (n) && (n) <= 1000000);
    res = n / 2;
    
    //@ assert res == n / 2;
    res = res - (res / 2);
    
    //@ assert res == (((n) / 2) - ((n) / 2) / 2);
    return res;
}
