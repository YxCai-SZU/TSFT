#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= n - 1 && n - 1 <= 99;
    //@ assert 1 <= m - 1 && m - 1 <= 99;
    //@ assert 1 <= (n - 1) * (m - 1) && (n - 1) * (m - 1) <= 9801;
    
    result = (n - 1) * (m - 1);
    
    //@ assert result == (((n) - 1) * ((m) - 1));
    return result;
}
