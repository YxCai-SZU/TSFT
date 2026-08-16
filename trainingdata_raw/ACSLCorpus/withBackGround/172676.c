#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer x) =
        0 <= a && a <= b && b <= 1000000000000000000 &&
        0 <= x && x <= 1000000000000000000;
*/

/*@
    requires in_range(a, b, x);
    ensures \result == (a <= x && x <= b + 1);
*/
bool is_possible_x_cats(long long a, long long b, long long x) {
    // Variable declarations at top of scope
    bool result;

    //@ assert a <= b + 1;
    //@ assert 0 <= a && a <= b && b <= 1000000000000000000 && 0 <= x && x <= 1000000000000000000;
    
    result = (a <= x && x <= (b + 1));
    return result;
}
