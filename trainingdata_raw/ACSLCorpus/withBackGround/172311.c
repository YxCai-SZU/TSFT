#include <stdbool.h>

/*@
    predicate can_reach(integer a, integer b, integer c) =
        c >= a + b;
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> c >= a + b;
    assigns \nothing;
 */
bool can_reach_value(int a, int b, int c)
{
    int sum;
    bool result;

    sum = a + b;
    //@ assert sum == a + b;

    result = (c >= sum);
    return result;
}
