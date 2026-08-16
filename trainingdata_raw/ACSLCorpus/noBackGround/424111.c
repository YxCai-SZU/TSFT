#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert n >= 1 && n <= 9;
    
    //@ assert n * n >= 1 && n * n <= 81;
    
    //@ assert n * n * n >= 1 && n * n * n <= 729;
    
    result = n * n * n;
    
    //@ assert result == ((n) * (n) * (n));
    
    return result;
}
