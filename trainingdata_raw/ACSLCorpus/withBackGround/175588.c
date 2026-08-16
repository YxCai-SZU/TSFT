#include <stdbool.h>

/*@
    predicate is_in_range(integer x) = 1 <= x <= 1000000000;
    predicate are_valid_params(integer a, integer b, integer c) = 
        is_in_range(a) && is_in_range(b) && is_in_range(c);
*/

/*@
    requires are_valid_params(a, b, c);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert are_valid_params(a, b, c);
    result = (b - a == c - b);
    
    //@ assert result == (b - a == c - b);
    return result;
}
