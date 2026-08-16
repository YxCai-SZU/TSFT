#include <limits.h>

/*@
    requires 1 <= x && x <= 10;
    requires x <= INT_MAX / (1 + x);
    requires x * (1 + x) <= INT_MAX / x;
    ensures \result == x * (1 + x * (1 + x));
    assigns \nothing;
*/
int func(int x)
{
    //@ assert 1 <= x && x <= 10;
    
    int x_squared;
    int result;
    
    //@ assert x * (1 + x) <= 10 * (1 + 10);
    x_squared = x * (1 + x);
    
    //@ assert x * (1 + x_squared) <= 10 * (1 + 10 * (1 + 10));
    //@ assert x * (1 + x_squared) >= 1 * (1 + 1 * (1 + 1));
    result = x * (1 + x_squared);
    
    //@ assert result == x * (1 + x * (1 + x));
    return result;
}
