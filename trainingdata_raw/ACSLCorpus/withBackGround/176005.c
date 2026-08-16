#include <limits.h>

/*@
    predicate is_valid_input(integer x) = -40 <= x <= 40;

    logic integer sign_func(integer x) =
        x > 0 ? 1 : (x < 0 ? -1 : 0);
*/

/*@
    requires is_valid_input(x);
    ensures (x > 0 ==> \result == 1);
    ensures (x < 0 ==> \result == -1);
    ensures (x == 0 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert is_valid_input(x);
    
    if (x > 0)
    {
        //@ assert x > 0;
        result = 1;
    }
    else if (x < 0)
    {
        //@ assert x < 0;
        result = -1;
    }
    else
    {
        //@ assert x == 0;
        result = 0;
    }
    
    //@ assert result == sign_func(x);
    return result;
}
