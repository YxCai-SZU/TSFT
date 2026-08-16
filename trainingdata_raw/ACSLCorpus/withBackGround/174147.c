#include <stdbool.h>

/*@ predicate a_in_range(integer a) = 1 <= a <= 16; */
/*@ predicate b_in_range(integer b) = 1 <= b <= 16; */
/*@ predicate sum_in_range(integer a, integer b) = a + b <= 16; */

/*@
    requires a_in_range(a) && b_in_range(b) && sum_in_range(a, b);
    ensures \result == (a <= 8 || b <= 8);
    assigns \nothing;
*/
bool func(long a, long b)
{
    bool ans = false;
    
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    //@ assert sum_in_range(a, b);
    
    if (a > 8 && b > 8) {
        ans = false;
    } else {
        ans = true;
    }
    
    //@ assert ans == (a <= 8 || b <= 8);
    return ans;
}
