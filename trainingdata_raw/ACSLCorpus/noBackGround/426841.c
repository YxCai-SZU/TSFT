#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b, unsigned long long c)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert a + b <= 200;
    
    result = (a + b >= c);
    
    //@ assert result == (a + b >= c);
    
    return result;
}
