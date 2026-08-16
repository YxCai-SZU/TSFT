#include <limits.h>

/*@
    predicate is_negative(integer x) = x < 0;
    predicate is_zero(integer x) = x == 0;
    predicate is_positive(integer x) = x > 0;
*/

/*@
    requires -1000 <= x <= 1000;
    ensures (x < 0 ==> \result == -1) && 
            (x == 0 ==> \result == 0) && 
            (x > 0 ==> \result == 1);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    if (x < 0)
    {
        //@ assert is_negative(x);
        result = -1;
    }
    else if (x == 0)
    {
        //@ assert is_zero(x);
        result = 0;
    }
    else
    {
        //@ assert is_positive(x);
        result = 1;
    }
    
    return result;
}
