#include <stddef.h>

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a <= 100 &&
        2 <= b <= 1000 &&
        b % 2 == 0;

    logic integer compute_result(integer a, integer b) =
        a > 12 ? b :
        (6 <= a && a <= 12) ? b / 2 :
        0;

    lemma result_bounds:
        \forall integer a, b;
        valid_input(a, b) ==>
        compute_result(a, b) >= 0 &&
        compute_result(a, b) <= b;

    lemma result_cases:
        \forall integer a, b;
        valid_input(a, b) ==>
        (a > 12 && compute_result(a, b) == b) ||
        (6 <= a && a <= 12 && compute_result(a, b) == b / 2) ||
        (a <= 5 && compute_result(a, b) == 0);
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    ensures \result >= 0 && \result <= b;
    ensures (a > 12 && \result == b) ||
            (6 <= a && a <= 12 && \result == b / 2) ||
            (a <= 5 && \result == 0);
*/
size_t func(size_t a, size_t b)
{
    size_t result;
    //@ assert valid_input(a, b);
    
    if (a > 12) {
        //@ assert a > 12;
        result = b;
        //@ assert result == b;
    } else if (a > 5) {
        //@ assert 6 <= a && a <= 12;
        result = b / 2;
        //@ assert result == b / 2;
    } else {
        //@ assert a <= 5;
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result == compute_result(a, b);
    return result;
}
