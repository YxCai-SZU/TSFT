#include <limits.h>

/*@
    requires (1 <= (n) <= 10);
    ensures \result == ((n) + (n) * (n) + (n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert (1 <= (n) <= 10);
    
    //@ assert n * n <= 100;
    //@ assert n * n * n <= 1000;
    
    result = n + n * n + n * n * n;
    
    //@ assert result == ((n) + (n) * (n) + (n) * (n) * (n));
    return result;
}
