#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures \result == (k <= (n + 1) / 2);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int k)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= 100;
    
    result = (k <= (n + 1) / 2);
    
    return result;
}
