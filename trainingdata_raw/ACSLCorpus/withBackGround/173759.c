#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == (a < b && b < c);
    assigns \nothing;
*/
bool func(int a, int b, int c) {
    // Variable declarations at top of scope
    bool result;

    //@ assert is_in_range(a);
    //@ assert is_in_range(b);
    //@ assert is_in_range(c);
    
    result = (a < b) && (b < c);
    return result;
}
