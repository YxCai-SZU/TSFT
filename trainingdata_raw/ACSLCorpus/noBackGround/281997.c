#include <stdbool.h>

/*@
    requires (1 <= (k) <= 100 && 1 <= (x) <= 100000);
    ensures \result == (500 * k >= x);
    assigns \nothing;
*/
bool func(long k, long x)
{
    // Variable declarations at scope top
    long scaled;
    bool result;

    //@ assert 1 <= k <= 100;
    //@ assert 1 <= x <= 100000;
    
    scaled = 500 * k;
    
    //@ assert 0 <= scaled <= 50000;
    
    result = (scaled >= x);
    
    //@ assert result == (500 * k >= x);
    
    return result;
}
