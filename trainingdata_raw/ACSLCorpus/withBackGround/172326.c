#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer compute_result(integer a, integer b) = 6 - a - b;

    lemma result_bounds: \forall integer a, b;
        valid_range(a, b) ==> 1 <= compute_result(a, b) <= 3;

    lemma result_distinct_a: \forall integer a, b;
        valid_range(a, b) ==> compute_result(a, b) != a;

    lemma result_distinct_b: \forall integer a, b;
        valid_range(a, b) ==> compute_result(a, b) != b;

    lemma sum_bounds: \forall integer a, b;
        valid_range(a, b) ==> 1 <= a + b <= 6;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    ensures 1 <= \result <= 3;
    ensures \result != a && \result != b;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    result = 6 - a - b;
    //@ assert result == compute_result(a, b);
    //@ assert 1 <= result <= 3;
    //@ assert result != a && result != b;
    return result;
}
