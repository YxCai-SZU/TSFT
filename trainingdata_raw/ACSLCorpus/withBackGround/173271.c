#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(h) && valid_range(w);
    ensures \result == ((h * h * 3) / 2 <= w * h);
    assigns \nothing;
*/
bool func(unsigned long long h, unsigned long long w)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= h && h <= 100;
    //@ assert 1 <= w && w <= 100;
    
    //@ assert h * h <= 10000;
    //@ assert h * h * 3 <= 30000;
    //@ assert (h * h * 3) / 2 <= 15000;
    //@ assert w * h <= 10000;
    
    //@ assert (h * h * 3) / 2 <= 15000;
    //@ assert w * h <= 10000;
    
    result = (h * h * 3) / 2 <= w * h;
    
    return result;
}
