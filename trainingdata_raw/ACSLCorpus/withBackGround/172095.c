#include <stdbool.h>

/*@
    predicate in_range(integer x) = -40 <= x <= 40;
    predicate is_integer(integer x) = x == (int)x;
*/

/*@
    requires in_range(x) && is_integer(x);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    bool result;
    int i;
    
    //@ assert in_range(x) && is_integer(x);
    
    if (x >= 30)
    {
        result = true;
    }
    else
    {
        i = 0;
        /*@
            loop invariant in_range(x) && is_integer(x);
            loop invariant 0 <= i <= 10000000;
            loop assigns i;
        */
        while (i < 10000000)
        {
            //@ assert i < 10000000;
            i = i + 1;
        }
        result = false;
    }
    
    //@ assert result == (x >= 30);
    return result;
}
