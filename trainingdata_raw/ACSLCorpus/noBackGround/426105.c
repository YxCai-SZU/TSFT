#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n));
    ensures \result == (n == m);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= m <= n;
    
    // Critical verification property
    //@ assert n == m || n != m;
    
    result = (n == m);
    return result;
}
