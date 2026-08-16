#include <limits.h>

/*@
    predicate a_in_range(integer a) = a >= INT_MIN && a <= INT_MAX;
    predicate b_in_range(integer b) = b >= INT_MIN && b <= INT_MAX;
    predicate ret_is_max(integer ret, integer a, integer b) = 
        (ret == a && a >= b) || (ret == b && b > a);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures ret_is_max(\result, a, b);
    assigns \nothing;
*/
int maximum_int(int a, int b) {
    int ret;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    
    if (a > b) {
        ret = a;
    } else {
        ret = b;
    }
    
    //@ assert ret_is_max(ret, a, b);
    return ret;
}
