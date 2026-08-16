#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c - a + b > 0) ? (c - a + b) : 0;

    lemma result_bounds:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_result(a, b, c) >= 0 &&
        compute_result(a, b, c) <= c;
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    // Variable declarations at scope top
    int result;

    //@ assert 1 <= b && b <= a && a <= 20;
    //@ assert 1 <= c && c <= 20;
    //@ assert c - a + b <= c;

    if (c - a + b > 0) {
        result = c - a + b;
    } else {
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= c;
    return result;
}
