#include <stdbool.h>

/*@
    requires (1 <= (n) <= 10000 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= n <= 10000 && 0 <= m <= n;
    
    //@ assert n == m ==> n == m;
    
    result = (n == m);
    
    //@ assert result == (n == m);
    
    return result;
}
