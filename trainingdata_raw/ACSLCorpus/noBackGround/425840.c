#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (a) && (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 100 * 100;
    
    result = n * n - a;
    
    //@ assert result == ((n) * (n) - (a));
    return result;
}

