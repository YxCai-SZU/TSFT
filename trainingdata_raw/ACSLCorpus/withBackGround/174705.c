#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a && a <= 100 && 2 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a * b) - (a + b - 1);

    lemma no_overflow_mul: \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;
    lemma no_overflow_add: \forall integer a, b; valid_range(a, b) ==> a + b - 1 <= 199;
    lemma no_underflow_sub: \forall integer a, b; valid_range(a, b) ==> (a * b) >= (a + b - 1);
    lemma result_consistent: \forall integer a, b; valid_range(a, b) ==> compute_result(a, b) == (a * b) - (a + b - 1);
*/

/*@
    requires 2 <= a && a <= 100;
    requires 2 <= b && b <= 100;
    ensures \result == (a * b) - (a + b - 1);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    //@ assert valid_range(a, b);
    //@ assert a * b <= 10000;
    //@ assert a + b - 1 <= 199;
    //@ assert (a * b) >= (a + b - 1);
    //@ assert compute_result(a, b) == (a * b) - (a + b - 1);
    
    return (a * b) - (a + b - 1);
}
