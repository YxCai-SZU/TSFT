#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == (d != 0 ? false : true);
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    bool result;
    
    if (d != 0)
    {
        //@ assert d != 0;
        result = false;
    }
    else
    {
        //@ assert d == 0;
        result = true;
    }
    
    return result;
}
