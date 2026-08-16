#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 20;

    logic integer multiply(integer a, integer b) = a * b;

    lemma multiplication_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==> multiply(a, b) <= 400;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert multiply(a, b) <= 400;
    return a * b;
}
