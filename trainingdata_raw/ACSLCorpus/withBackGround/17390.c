#include <limits.h>

/*@
    predicate valid_input(integer i) = 1 <= i && i <= 10;
    predicate valid_result(integer i, integer r) = r == i * 100 + 100;
*/

/*@
    requires valid_input(input);
    ensures valid_result(input, \result);
    assigns \nothing;
*/
int func(int input)
{
    int result;

    // Declare all variables at scope top
    result = input * 100 + 100;

    //@ assert 1 * 100 + 100 <= result <= 10 * 100 + 100;
    //@ assert 200 <= result <= 20000;
    //@ assert result == input * 100 + 100;

    return result;
}
