#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;

    logic integer compute_result(integer a) = a * 50 + 10 * a * a;

    lemma overflow_bound1: \forall integer a; valid_range(a) ==> a * 50 <= 500;
    lemma overflow_bound2: \forall integer a; valid_range(a) ==> a * a <= 100;
    lemma overflow_bound3: \forall integer a; valid_range(a) ==> a * 50 + 10 * a * a <= 1500;
*/

/*@
    requires 1 <= a && a <= 10;
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert a * 50 <= 500;
    //@ assert a * a <= 100;
    //@ assert a * 50 + 10 * a * a <= 1500;

    result = (int32_t)(a * 50 + 10 * a * a);
    return result;
}
