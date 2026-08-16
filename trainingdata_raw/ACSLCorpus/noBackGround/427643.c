#include <limits.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result == ((n) * (m) - ((n) - 1) - (m) + 1);
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= m && m <= 20;
    
    // Arithmetic bounds verification
    //@ assert n * m >= 1 && n * m <= 400;
    
    // Compute result
    result = n * m - (n - 1) - m + 1;
    
    // Postcondition verification
    //@ assert result == ((n) * (m) - ((n) - 1) - (m) + 1);
    //@ assert result >= 1;
    
    return result;
}
