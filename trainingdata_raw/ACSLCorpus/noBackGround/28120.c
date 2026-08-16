#include <stddef.h>

/*@
    requires 2 <= k <= 100;
    ensures \result == (k / 2) * ((k + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t k)
{
    //@ assert 2 <= k <= 100;
    
    //@ assert k / 2 <= k;
    //@ assert (k + 1) / 2 <= k + 1;
    
    //@ assert (k / 2) * ((k + 1) / 2) <= k * (k + 1) / 2;
    //@ assert (k / 2) * ((k + 1) / 2) <= 50 * 51;
    
    return (k / 2) * ((k + 1) / 2);
}
