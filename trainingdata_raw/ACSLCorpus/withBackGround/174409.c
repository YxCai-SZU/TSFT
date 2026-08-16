#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - a - b + 1;

    lemma result_positive:
        \forall integer a, b; valid_range(a, b) ==> compute_result(a, b) > 0;

    lemma no_overflow:
        \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;

    lemma no_underflow:
        \forall integer a, b; valid_range(a, b) ==> a * b >= a + b;
*/

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert valid_range(a, b);
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b + 1 > 0;

    result = a * b - a - b + 1;
    return result;
}
