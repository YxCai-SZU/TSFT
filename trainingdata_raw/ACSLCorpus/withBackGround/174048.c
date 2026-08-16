#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == true <==> a < c;
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    bool result;
    
    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    
    if (a >= c)
    {
        //@ assert a >= c;
        result = false;
    }
    else
    {
        //@ assert a < c;
        result = true;
    }
    
    //@ assert result == true <==> a < c;
    return result;
}
