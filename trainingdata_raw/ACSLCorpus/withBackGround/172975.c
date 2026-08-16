#include <limits.h>

/*@
    predicate valid_input(integer A, integer B) =
        2 <= A && A <= 100 &&
        2 <= B && B <= 100;

    logic integer compute_result(integer A, integer B) =
        (A - 1) * (B - 1);

    lemma subtraction_bounds:
        \forall integer A, B;
        valid_input(A, B) ==>
        A - 1 >= 1 && B - 1 >= 1;

    lemma result_bounds:
        \forall integer A, B;
        valid_input(A, B) ==>
        compute_result(A, B) >= 1 &&
        compute_result(A, B) <= 99 * 99;
*/

/*@
    requires valid_input(A, B);
    ensures \result == compute_result(A, B);
    assigns \nothing;
*/
int func(int A, int B)
{
    int result;

    //@ assert A - 1 >= 1;
    //@ assert B - 1 >= 1;
    //@ assert (A - 1) * (B - 1) >= 1;
    //@ assert (A - 1) * (B - 1) <= 99 * 99;

    result = (A - 1) * (B - 1);
    return result;
}
