#include <limits.h>

/*@
    predicate is_abs(integer x, integer result) =
        result >= 0 && (result == x || result == -x);
*/

/*@
    requires -1000 <= x <= 1000;
    ensures \result >= 0;
    ensures is_abs(x, \result);
*/
int func(int x)
{
    int result;
    
    if (x < 0) {
        result = -x;
    } else {
        result = x;
    }
    
    //@ assert result >= 0;
    //@ assert result == x || result == -x;
    
    return result;
}
