#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate x_in_range(integer x) = 1 <= x <= 200;
    predicate result_condition(integer a, integer b, integer x, bool result) =
        result == (a <= x && x <= a + b);
*/

/*@
    requires a_in_range(a);
    requires b_in_range(b);
    requires x_in_range(x);
    ensures result_condition(a, b, x, \result);
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    // Proof assertions
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= x <= 200;

    result = (a <= x) && (x <= a + b);
    return result;
}
