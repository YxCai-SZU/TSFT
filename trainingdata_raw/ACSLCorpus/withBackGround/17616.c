#include <stdbool.h>

/*@ predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    predicate result_condition(integer a, integer b, bool result) = 
        result == (a > b);
 */

/*@ requires a_in_range(a);
    requires b_in_range(b);
    ensures result_condition(a, b, \result);
    assigns \nothing;
 */
bool func(int a, int b)
{
    //@ assert a_in_range(a);
    //@ assert b_in_range(b);
    return a > b;
}
