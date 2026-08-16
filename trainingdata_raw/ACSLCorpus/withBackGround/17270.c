#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer x) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= x && x <= 200;

    logic integer min_val(integer a, integer b, integer x) =
        a > x ? a - x : 0;

    logic integer max_val(integer a, integer b, integer x) =
        b + a < x ? x - b - a : 0;

    lemma min_val_nonnegative:
        \forall integer a, b, x;
        in_range(a, b, x) ==> min_val(a, b, x) >= 0;
*/

/*@
    requires in_range(a, b, x);
    ensures \result == (x - a >= 0 && x - a <= b);
    assigns \nothing;
*/
bool func(long a, long b, long x)
{
    long min_val;
    long max_val;
    bool result;

    //@ assert in_range(a, b, x);
    
    min_val = a > x ? a - x : 0;
    max_val = b + a < x ? x - b - a : 0;
    
    //@ assert min_val >= 0;
    
    result = (x - a >= 0 && x - a <= b);
    return result;
}
