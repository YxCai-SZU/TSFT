#include <stdint.h>

/*@
    predicate is_within_bounds(integer a) =
        1 <= a && a <= 10;

    logic integer compute_result(integer a) =
        a + a * a + a * a * a;

    lemma a_squared_bound:
        \forall integer a; is_within_bounds(a) ==> a * a <= 100;

    lemma a_cubed_bound:
        \forall integer a; is_within_bounds(a) ==> a * a * a <= 1000;
*/

/*@
    requires is_within_bounds(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_2;
    int64_t result;

    //@ assert is_within_bounds(a);
    //@ assert a * a <= 100;
    a_2 = a * a;

    //@ assert a * a_2 <= 1000;
    result = a + a_2 + a * a_2;

    //@ assert result == compute_result(a);
    return result;
}
