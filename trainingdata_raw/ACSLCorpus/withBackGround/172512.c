#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10000;
    
    logic integer conditional_sum(integer a, integer b, integer c) =
        a < b ? a + c : b + c;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    requires valid_range(d);
    ensures \result >= 0;
    ensures \result == conditional_sum(a, b, c);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans;
    int64_t sub;
    int64_t add;
    int64_t temp;
    
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    if (a < b) {
        ans = a + c;
        //@ assert a >= 1 && a <= 10000;
    } else {
        ans = b + c;
        //@ assert b >= 1 && b <= 10000;
    }
    
    //@ assert ans == conditional_sum(a, b, c);
    //@ assert ans >= 0;
    
    return ans;
}
