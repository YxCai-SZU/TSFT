#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 3 &&
        1 <= b <= 3 &&
        a != b;

    predicate valid_result(integer a, integer b, integer r) =
        r == 6 - a - b &&
        r >= 1 &&
        r <= 3 &&
        r != a &&
        r != b;

    logic integer compute_result(integer a, integer b) = 6 - a - b;

    lemma bounds_lemma:
        \forall integer a, b;
        valid_input(a, b) ==>
        compute_result(a, b) >= 1 &&
        compute_result(a, b) <= 3;

    lemma distinct_lemma:
        \forall integer a, b;
        valid_input(a, b) ==>
        compute_result(a, b) != a &&
        compute_result(a, b) != b;
*/

/*@
    requires valid_input(a, b);
    ensures valid_result(a, b, \result);
*/
size_t func(size_t a, size_t b)
{
    // Declarations at top of scope
    size_t result;

    //@ assert a + b <= 6;
    //@ assert 6 - a - b >= 1;
    //@ assert 6 - a - b <= 3;

    result = 6 - a - b;

    //@ assert result >= 1;
    //@ assert result <= 3;
    //@ assert result != a;
    //@ assert result != b;

    return result;
}
