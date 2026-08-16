#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(int n, int m)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert n <= 100;
    //@ assert m <= n;
    
    result = (n == m);
    return result;
}
