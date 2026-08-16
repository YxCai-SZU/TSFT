#include <stdint.h>

/*@
    predicate valid_range(integer x) = 2 <= x <= 100;

    logic integer compute_result(integer a, integer b) = a * b - (a + b - 1);

    lemma product_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b <= 10000;
    lemma sum_bound: \forall integer a, b; valid_range(a) && valid_range(b) ==> a + b - 1 <= 199;
    lemma non_negative: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b >= a + b - 1;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    // Variable declarations at scope top
    uint32_t result;

    // Precondition assertions
    //@ assert valid_range(a);
    //@ assert valid_range(b);

    // Mathematical property verification
    //@ assert a * b <= 10000;
    //@ assert a + b - 1 <= 199;
    //@ assert a * b >= a + b - 1;

    result = a * b - (a + b - 1);
    
    // Postcondition verification
    //@ assert result == compute_result(a, b);
    
    return result;
}
