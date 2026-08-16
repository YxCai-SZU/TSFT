#include <stdbool.h>

/*@ predicate is_target(integer x) = x == 7 || x == 5 || x == 3; */

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 7 || x == 5 || x == 3);
    ensures \result <==> is_target(x);
*/
bool func(long x)
{
    //@ assert 1 <= x && x <= 9;
    
    if (x == 7 || x == 5 || x == 3)
    {
        //@ assert is_target(x);
        return true;
    }
    else
    {
        //@ assert !is_target(x);
        return false;
    }
}
