#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 13;
    predicate valid_array(int *a) = 
        \valid(a) && \valid(a+1) && \valid(a+2) &&
        valid_range(a[0]) && valid_range(a[1]) && valid_range(a[2]);
*/

/*@
    logic integer diff_safe(integer x, integer y) = x - y;
    lemma diff_bounds:
        \forall integer x, y; valid_range(x) && valid_range(y) ==> -12 <= diff_safe(x, y) <= 12;
*/

/*@
    requires valid_array(a);
    ensures \result == (diff_safe(a[1], a[0]) == diff_safe(a[2], a[1]));
    assigns \nothing;
*/
bool func(int *a) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert valid_range(a[0]);
    //@ assert valid_range(a[1]);
    //@ assert valid_range(a[2]);
    
    //@ assert -12 <= diff_safe(a[1], a[0]) <= 12;
    //@ assert -12 <= diff_safe(a[2], a[1]) <= 12;
    
    result = (a[1] - a[0]) == (a[2] - a[1]);
    return result;
}
