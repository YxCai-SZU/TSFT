#include <stdint.h>

/*@
    predicate valid_range(integer a) =
        0 <= a && a < 1000;

    logic integer compute_result(integer a, integer b) =
        a * 100 + b * 10;

    lemma result_bounds:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            compute_result(a, b) < 1000 * 100 + 1000 * 10;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert compute_result(a, b) < 1000 * 100 + 1000 * 10;
    
    return a * 100 + b * 10;
}
