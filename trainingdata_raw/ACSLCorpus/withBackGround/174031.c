#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        2 <= a <= 100 && 2 <= b <= 100;

    logic integer compute_result(integer a, integer b) =
        a * b - (a + b - 1);

    lemma sum_bound: \forall integer a, b; valid_range(a, b) ==> a + b - 1 <= 199;
    lemma product_bound: \forall integer a, b; valid_range(a, b) ==> a * b <= 10000;
    lemma non_negative: \forall integer a, b; valid_range(a, b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a, b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    int32_t result;

    //@ assert a + b - 1 <= 199;
    //@ assert a * b <= 10000;
    //@ assert a * b >= a + b - 1;
    
    result = (int32_t)(a * b - (a + b - 1));
    return result;
}
