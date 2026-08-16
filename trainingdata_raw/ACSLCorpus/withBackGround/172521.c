#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c, integer d, integer e) =
        a < b && b < c && c < d && d < e;

    predicate within_bounds(integer a, integer b, integer c, integer d, integer e, integer k) =
        a < 0x80000000 && b < 0x80000000 && c < 0x80000000 &&
        d < 0x80000000 && e < 0x80000000 && k < 0x80000000;

    logic integer abs_diff(integer x, integer y) =
        x >= y ? x - y : y - x;
*/

/*@
    requires within_bounds(a, b, c, d, e, k);
    requires is_ordered(a, b, c, d, e);
    ensures \result == true <==> (e - a <= k);
*/
bool func(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int diff;
    bool is_less_or_equal;
    
    //@ assert a < b && b < c && c < d && d < e;
    
    if (e >= a) {
        diff = e - a;
    } else {
        diff = a - e;
    }
    
    //@ assert diff == abs_diff(e, a);
    
    if (diff <= k) {
        is_less_or_equal = true;
    } else {
        is_less_or_equal = false;
    }
    
    //@ assert is_less_or_equal == (diff <= k);
    //@ assert diff == e - a || diff == a - e;
    //@ assert is_less_or_equal == true <==> (e - a <= k);
    
    return is_less_or_equal;
}
