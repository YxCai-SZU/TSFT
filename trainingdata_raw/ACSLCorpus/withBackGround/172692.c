#include <stdbool.h>

/*@
    predicate bounds_a(integer a) = 2 <= a && a <= 100;
    predicate bounds_b(integer b) = 2 <= b && b <= 100;
    logic integer compute_result(integer a, integer b) = (a - 1) * (b - 1);
    lemma result_bounds: \forall integer a, b; bounds_a(a) && bounds_b(b) ==> 1 <= compute_result(a, b) && compute_result(a, b) <= 9801;
*/

/*@
    requires bounds_a(a) && bounds_b(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;

    //@ assert bounds_a(a);
    //@ assert bounds_b(b);
    //@ assert 1 <= a - 1 && a - 1 <= 99;
    //@ assert 1 <= b - 1 && b - 1 <= 99;
    //@ assert 1 <= (a - 1) * (b - 1) && (a - 1) * (b - 1) <= 9801;

    result = (a - 1) * (b - 1);
    return result;
}
