#include <stddef.h>

/*@
    requires (1 <= (n) && 1 <= (a) && 1 <= (b) &&
        (n) <= 20 && (a) <= 100 && (b) <= 2000);
    ensures \result == n * a || \result == b;
    ensures \result <= b;
    assigns \nothing;
*/
size_t func(size_t n, size_t a, size_t b)
{
    //@ assert (1 <= (n) && 1 <= (a) && 1 <= (b) &&         (n) <= 20 && (a) <= 100 && (b) <= 2000);
    //@ assert ((n) * (a)) <= 2000;
    
    size_t product = n * a;
    size_t ret;
    
    if (product < b)
    {
        ret = product;
    }
    else
    {
        ret = b;
    }
    
    //@ assert ret == n * a || ret == b;
    //@ assert ret <= b;
    
    return ret;
}
