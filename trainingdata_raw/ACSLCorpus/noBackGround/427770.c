#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == (2 * a <= b);
    assigns \nothing;
*/
bool func(long a, long b)
{
    // Variable declarations at top of scope
    long x;
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    //@ assert 2 * a <= 200;
    
    x = a * 2;
    result = (x <= b);
    
    //@ assert result == (2 * a <= b);
    return result;
}
