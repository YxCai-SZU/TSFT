#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a - 2 * b > 0 ? a - 2 * b : 0;

    lemma result_nonnegative:
        \forall integer a, b;
            valid_range(a, b) ==> compute_result(a, b) >= 0;

    lemma result_cases:
        \forall integer a, b;
            valid_range(a, b) ==>
                compute_result(a, b) == a - 2 * b ||
                compute_result(a, b) == 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert a - 2 * b >= 0 || a - 2 * b < 0;
    result = (a - 2 * b > 0) ? (a - 2 * b) : 0;
    return result;
}

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func1(int a, int b)
{
    int result;
    //@ assert a - 2 * b >= 0 || a - 2 * b < 0;
    result = (a - 2 * b > 0) ? (a - 2 * b) : 0;
    return result;
}

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
    assigns \nothing;
*/
int func2(int a, int b)
{
    int result;
    //@ assert a - 2 * b >= 0 || a - 2 * b < 0;
    //@ assert a - 2 * b >= 0 || a - 2 * b < 0;
    //@ assert a - 2 * b >= 0 || a - 2 * b < 0;
    result = (a - 2 * b > 0) ? (a - 2 * b) : 0;
    return result;
}
