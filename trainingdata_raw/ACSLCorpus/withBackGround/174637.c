#include <stdbool.h>

/*@
    predicate is_ge_30(integer x) = x >= 30;
    predicate is_lt_30(integer x) = x < 30;
*/

/*@
    requires -40 <= x <= 40;
    ensures \result ==> is_ge_30(x);
    ensures !\result ==> is_lt_30(x);
*/
bool func(int x)
{
    bool ret;
    
    //@ assert -40 <= x <= 40;
    
    if (x >= 30) {
        //@ assert is_ge_30(x);
        ret = true;
    } else {
        //@ assert is_lt_30(x);
        ret = false;
    }
    
    return ret;
}
