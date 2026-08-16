#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate result_condition(integer a, integer b, bool result) =
        result == (a % 2 == 0 || b % 2 == 0);
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == (a % 2 == 0 || b % 2 == 0);
    ensures result_condition(a, b, \result);
*/
bool func(unsigned int a, unsigned int b)
{
    bool a_is_even;
    bool b_is_even;
    bool result;

    a_is_even = (a % 2 == 0);
    b_is_even = (b % 2 == 0);

    if (a_is_even || b_is_even)
    {
        //@ assert a_is_even || b_is_even;
        result = true;
        return result;
    }

    //@ assert !a_is_even && !b_is_even;
    result = false;
    return result;
}
