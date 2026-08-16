#include <limits.h>

/*@
    predicate is_min(integer ret, integer x, integer y) =
        (ret == x || ret == y) &&
        ret <= x &&
        ret <= y;
*/

/*@
    lemma min_proof:
        \forall integer x, y;
        (x < y ==> x <= x && x <= y) &&
        (x >= y ==> y <= x && y <= y);
*/

/*@
    requires INT_MIN <= x <= INT_MAX;
    requires INT_MIN <= y <= INT_MAX;
    ensures \result == x || \result == y;
    ensures \result <= x;
    ensures \result <= y;
    ensures is_min(\result, x, y);
*/
int min_int(int x, int y) {
    int ret;
    
    //@ assert INT_MIN <= x <= INT_MAX;
    //@ assert INT_MIN <= y <= INT_MAX;
    
    if (x < y) {
        //@ assert x <= x;
        //@ assert x <= y;
        ret = x;
    } else {
        //@ assert y <= x;
        //@ assert y <= y;
        ret = y;
    }
    
    //@ assert is_min(ret, x, y);
    return ret;
}
