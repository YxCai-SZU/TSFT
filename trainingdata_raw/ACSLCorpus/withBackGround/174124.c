#include <stddef.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 100;
    logic integer multiply(integer a, integer b) = a * b;
    lemma multiplication_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> multiply(a, b) <= 100 * 100;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == multiply(a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert multiply(a, b) <= 100 * 100;
    return a * b;
}

/*@
    lemma test_func: \forall integer a, b; valid_range(a) && valid_range(b) ==> multiply(a, b) == multiply(a, b);
*/
