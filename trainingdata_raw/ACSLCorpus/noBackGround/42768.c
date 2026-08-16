#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 9);
    ensures \result == ((n) * (n) * (n));
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert (1 <= (n) && (n) <= 9);
    
    //@ assert n * n <= 81;
    //@ assert n * n * n <= 729;
    
    result = n * n * n;
    
    //@ assert result == ((n) * (n) * (n));
    return result;
}
