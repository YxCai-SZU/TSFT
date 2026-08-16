#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer x) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= x && x <= 200;

    predicate result_condition(integer a, integer b, integer x, bool r) =
        r == (a <= x && x <= a + b);

    lemma no_overflow_sum: \forall integer a, b;
        valid_input(a, b, 0) ==> a + b <= 200;

    lemma no_overflow_diff: \forall integer a, x;
        valid_input(a, 0, x) ==> x - a <= 200;

    lemma no_underflow_diff: \forall integer a, x;
        valid_input(a, 0, x) ==> x >= a || x - a >= 0;
*/

/*@
    requires valid_input(a, b, x);
    ensures result_condition(a, b, x, \result);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= x && x <= 200;
    //@ assert a + b <= 200;
    //@ assert x - a <= 200;

    result = (a <= x) && (x <= a + b);
    return result;
}
