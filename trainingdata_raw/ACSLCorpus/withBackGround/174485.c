#include <limits.h>

/*@ predicate is_max(integer a, integer b, integer ret) =
    ret >= INT_MIN &&
    (ret == a || ret == b) &&
    ret >= a &&
    ret >= b;
*/

/*@ lemma max_property:
    \forall integer a, b;
    a >= INT_MIN && b >= INT_MIN ==>
    (a > b ==> is_max(a, b, a)) &&
    (!(a > b) ==> is_max(a, b, b));
*/

/*@
    requires a >= INT_MIN;
    requires b >= INT_MIN;
    ensures \result >= INT_MIN;
    ensures \result == a || \result == b;
    ensures \result >= a;
    ensures \result >= b;
    ensures is_max(a, b, \result);
*/
int maximum_int(int a, int b) {
    int ret;
    
    //@ assert a >= INT_MIN && b >= INT_MIN;
    
    if (a > b) {
        //@ assert a >= INT_MIN;
        //@ assert a >= a;
        //@ assert a >= b;
        ret = a;
    } else {
        //@ assert b >= INT_MIN;
        //@ assert b >= a;
        //@ assert b >= b;
        ret = b;
    }
    
    //@ assert is_max(a, b, ret);
    return ret;
}
