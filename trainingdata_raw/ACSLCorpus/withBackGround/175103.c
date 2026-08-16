#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123 &&
        0 <= d <= 123 && 0 <= e <= 123 && 0 <= k <= 123 &&
        a < b && b < c && c < d && d < e;

    predicate condition_holds(integer a, integer b, integer c, integer d, integer e, integer k) =
        (b - a <= k) || (c - a <= k) || (d - a <= k) || (e - a <= k);
*/

/*@
    requires is_valid_range(a, b, c, d, e, k);
    ensures \result == \true <==> condition_holds(a, b, c, d, e, k);
    assigns \nothing;
*/
bool func(long a, long b, long c, long d, long e, long k) {
    bool contains = false;

    //@ assert a < b && b < c && c < d && d < e;
    
    //@ assert e - a > 0;
    //@ assert e - a <= 123;

    if (b - a <= k) {
        contains = true;
    } else if (c - a <= k) {
        contains = true;
    } else if (d - a <= k) {
        contains = true;
    } else if (e - a <= k) {
        contains = true;
    }

    //@ assert contains == \true <==> condition_holds(a, b, c, d, e, k);
    return contains;
}
