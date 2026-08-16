#include <stdint.h>

/*@
    requires (2 <= (n) <= 100) && (2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    // Variable declarations at scope top
    int32_t result;
    
    // Precondition verification
    //@ assert 2 <= n <= 100;
    //@ assert 2 <= m <= 100;
    
    // Intermediate bounds verification
    //@ assert 1 <= n - 1 <= 99;
    //@ assert 1 <= m - 1 <= 99;
    
    // Result computation
    result = (n - 1) * (m - 1);
    
    // Postcondition verification
    //@ assert result == (((n) - 1) * ((m) - 1));
    
    return result;
}
