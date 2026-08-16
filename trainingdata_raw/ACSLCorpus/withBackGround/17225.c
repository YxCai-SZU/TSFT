#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_expr(integer a, integer b, integer c, integer d) =
        a + b + 1 - c - d;

    lemma expr_positive_implies:
        \forall integer a, b, c, d;
            valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d) &&
            (a - c <= d) && (compute_expr(a, b, c, d) > 0) ==>
            (a - c <= d) && (compute_expr(a, b, c, d) > 0);
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == ((a - c <= d) && (a + b + 1 - c - d > 0));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert valid_range(d);
    //@ assert (a - c <= d) && (a + b + 1 - c - d > 0) ==> ((a - c <= d) && (a + b + 1 - c - d > 0));
    
    if (a - c <= d && a + b + 1 - c - d > 0) {
        return true;
    } else {
        return false;
    }
}
