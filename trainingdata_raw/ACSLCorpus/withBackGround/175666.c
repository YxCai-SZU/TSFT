#include <stdbool.h>

/*@
    predicate is_one(integer x) = x == 1;
    predicate is_zero(integer x) = x == 0;
*/

/*@
    requires x <= 1;
    ensures (is_one(x) ==> \result == 0) && (is_zero(x) ==> \result == 1);
    assigns \nothing;
*/
int func(unsigned int x) {
    int res;
    
    if (x == 1) {
        res = 0;
    } else {
        //@ assert is_zero(x);
        res = 1;
    }
    
    return res;
}
