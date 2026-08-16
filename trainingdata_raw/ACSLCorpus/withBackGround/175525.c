#include <stdbool.h>

/*@
    predicate is_ge_30(integer x) = x >= 30;
    predicate is_lt_30(integer x) = x < 30;
*/

/*@
    requires -40 <= x <= 40;
    ensures \result == true ==> is_ge_30(x);
    ensures \result == false ==> is_lt_30(x);
*/
bool func(long x)
{
    bool result;
    
    //@ assert x >= -40 && x <= 40;
    
    //@ assert x >= 30 ==> is_ge_30(x);
    
    result = (x >= 30);
    
    //@ assert result == true ==> is_ge_30(x);
    //@ assert result == false ==> is_lt_30(x);
    
    return result;
}
