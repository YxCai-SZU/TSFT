#include <stdbool.h>

/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    logic integer complement(integer x) = (x == 0) ? 1 : 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    //@ assert x == 0 || x == 1;
    
    if (x == 0) {
        result = 1;
        //@ assert result == 1;
    } else {
        //@ assert x == 1;
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert (x == 0 && result == 1) || (x == 1 && result == 0);
    return result;
}
