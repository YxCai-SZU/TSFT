#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 179; */

/*@
    requires is_valid_range(x);
    ensures \result == 360 - x;
    ensures 1 <= \result <= 360;
*/
int func(int x)
{
    int result;
    
    //@ assert is_valid_range(x);
    //@ assert 1 <= 360 - x <= 360;
    
    result = 360 - x;
    
    //@ assert result == 360 - x;
    //@ assert 1 <= result <= 360;
    
    return result;
}
