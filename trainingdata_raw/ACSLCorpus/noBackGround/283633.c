#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;

    //@ assert (1 <= (n) && (n) <= 10000);
    ans = (1000 - n % 1000) % 1000;
    
    //@ assert ans == ((1000 - (n) % 1000) % 1000);
    //@ assert ans < 1000;
    
    return ans;
}
