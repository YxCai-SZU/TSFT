#include <stdbool.h>

/*@
    predicate is_one(integer x) = x == 1;
    predicate is_zero(integer x) = x == 0;
*/

/*@
    requires 0 <= x <= 1;
    ensures (x == 1 ==> \result == 0);
    ensures (x == 0 ==> \result == 1);
*/
int func(int x)
{
    int result;
    
    if (x == 1) {
        //@ assert is_one(x);
        result = 0;
    } else {
        //@ assert is_zero(x);
        result = 1;
    }
    
    return result;
}
