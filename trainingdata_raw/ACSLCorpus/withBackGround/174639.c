#include <limits.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer target_result(integer a, integer b) =
        a * b - a - b + 1;

    lemma bounds_lemma:
        \forall integer a, b;
        valid_range(a, b) ==>
        target_result(a, b) <= INT_MAX &&
        target_result(a, b) >= INT_MIN;
*/

/*@
    requires valid_range(a, b);
    ensures \result == target_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert valid_range(a, b);
    //@ assert 2 * 2 <= a * b <= 100 * 100;
    //@ assert a * b - a >= 0;
    //@ assert a * b - a - b >= -100;
    //@ assert target_result(a, b) <= INT_MAX;
    //@ assert target_result(a, b) >= INT_MIN;
    
    return a * b - a - b + 1;
}
