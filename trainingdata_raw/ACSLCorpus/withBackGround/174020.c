#include <stddef.h>

/*@
    predicate valid_range(integer a) = 2 <= a && a <= 100;

    logic integer compute_result(integer a, integer b) = a * b - a - b + 1;

    lemma result_positive: \forall integer a, b; valid_range(a) && valid_range(b) ==> compute_result(a, b) > 0;
    lemma result_upper_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> compute_result(a, b) <= 10000 - 100 - 100 + 1;
    lemma result_lower_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> compute_result(a, b) >= 4 - 100 - 100 + 1;
*/

/*@
    requires 2 <= A <= 100;
    requires 2 <= B <= 100;
    ensures \result == A * B - A - B + 1;
    ensures \result > 0;
*/
size_t func(size_t A, size_t B)
{
    // Variable declarations at top of scope
    size_t result;

    //@ assert 2 <= A && A <= 100;
    //@ assert 2 <= B && B <= 100;
    //@ assert A * B <= 100 * 100;
    //@ assert A * B >= 2 * 2;
    //@ assert A * B - A >= 2 * 2 - 100;
    //@ assert A * B >= A + B;
    //@ assert A * B - A - B >= 2 * 2 - 100 - 100;
    //@ assert A * B - A - B + 1 <= 18446744073709551615UL;
    //@ assert A * B - A - B + 1 >= 0;

    result = A * B - A - B + 1;
    return result;
}
