#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == (((n) - 1) / 2 + 1);
    ensures \result >= 1;
    ensures \result <= 500000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ans;
    
    //@ assert (1 <= (n) && (n) <= 1000000);
    ans = (n - 1) / 2 + 1;
    
    //@ assert ans == (((n) - 1) / 2 + 1);
    //@ assert ans >= 1;
    //@ assert ans <= 500000;
    
    return ans;
}
