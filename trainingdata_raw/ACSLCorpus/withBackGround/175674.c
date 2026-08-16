#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    logic integer compute_result(integer a, integer b) =
        a + b < 10 ? a + b : a + b - 10;

    lemma result_correctness:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        compute_result(a, b) == (a + b < 10 ? a + b : a + b - 10);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == compute_result(a, b);
    ensures (a + b < 10 ==> \result == a + b);
    ensures (a + b >= 10 ==> \result == a + b - 10);
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t sum;
    uint32_t result;

    //@ assert valid_range(a) && valid_range(b);
    sum = a + b;
    
    if (sum < 10) {
        result = sum;
        //@ assert result == a + b;
    } else {
        result = sum - 10;
        //@ assert result == a + b - 10;
    }
    
    //@ assert result == compute_result(a, b);
    return result;
}
