#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 1000000000;

    logic integer calculate_diff(integer a, integer b, integer c) = c - (b - a);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == (calculate_diff(a, b, c) > 0);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c)
{
    // Variable declarations at scope top
    long long diff;
    bool result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);

    diff = c - (b - a);
    result = diff > 0;
    
    return result;
}
