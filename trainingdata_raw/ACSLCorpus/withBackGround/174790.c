#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 &&
        2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma multiplication_bound:
        \forall integer a, b;
            valid_range(a, b) ==> a * b <= 10000;

    lemma subtraction_safe:
        \forall integer a, b;
            valid_range(a, b) ==> a * b >= a + b - 1;

    lemma sum_bound:
        \forall integer a, b;
            valid_range(a, b) ==> a + b - 1 <= 199;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at scope top
    uint32_t ans;
    int32_t res;

    //@ assert valid_range(a, b);
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;
    //@ assert a + b - 1 <= 199;

    ans = a * b - (a + b - 1);
    res = (int32_t)ans;
    return res;
}
