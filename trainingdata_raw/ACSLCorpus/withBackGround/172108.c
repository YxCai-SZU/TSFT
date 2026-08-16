#include <stdbool.h>

/*@
    predicate is_mod_condition(integer x) =
        x % 3 == 0 || x % 3 == 1;
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == 1 || \result == 0;
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert 1 <= x <= 100;
    
    if (x % 3 == 0 || x % 3 == 1)
    {
        //@ assert is_mod_condition(x);
        result = 1;
    }
    else
    {
        //@ assert !is_mod_condition(x);
        result = 0;
    }
    
    //@ assert result == 1 || result == 0;
    return result;
}
