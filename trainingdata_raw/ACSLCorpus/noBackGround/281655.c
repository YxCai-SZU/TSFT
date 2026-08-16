#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100 && 0 <= (b) <= (a));
    ensures ((\result) == ((a) - (b) == (b)));
    assigns \nothing;
*/
bool func(long a, long b)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 0 <= b <= a;
    
    result = (a - b == b);
    
    //@ assert ((result) == ((a) - (b) == (b)));
    return result;
}
