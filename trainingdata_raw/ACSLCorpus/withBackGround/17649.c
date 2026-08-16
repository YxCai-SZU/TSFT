#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a && a <= 4500 &&
        0 <= b && b <= 5000 &&
        a + b <= 9500;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds: \forall integer a, b; valid_input(a, b) ==> 0 <= sum(a, b) && sum(a, b) <= 9500;
*/

/*@
    requires valid_input(a, b);
    ensures \result == sum(a, b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 0 <= a && a <= 4500;
    //@ assert 0 <= b && b <= 5000;
    //@ assert a + b <= 9500;

    result = a + b;

    //@ assert result == sum(a, b);
    return result;
}
