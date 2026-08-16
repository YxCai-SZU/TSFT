#include <limits.h>

/*@
    requires (1 <= (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int n2;
    int result;
    
    //@ assert 1 <= n <= 9;
    
    //@ assert n * n <= 81;
    n2 = n * n;
    
    //@ assert n2 * n <= 729;
    result = n2 * n;
    
    return result;
}
