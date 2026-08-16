#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer expected_result(integer a, integer b, integer c) =
        (a - b + c > 0) ? (a - b + c) : 0;

    lemma result_nonnegative:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> expected_result(a, b, c) >= 0;

    lemma result_bound:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> expected_result(a, b, c) <= a - b + c;

    lemma result_cases:
        \forall integer a, b, c;
        valid_input(a, b, c) ==> 
            (expected_result(a, b, c) == a - b + c) ||
            (expected_result(a, b, c) == 0);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= a - b + c;
    ensures \result == a - b + c || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert a - b + c >= 0 || a - b + c == 0;
    
    if (a - b + c > 0) {
        result = a - b + c;
    } else {
        result = 0;
    }
    
    return result;
}
