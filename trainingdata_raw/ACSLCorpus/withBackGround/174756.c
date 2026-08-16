#include <stdint.h>
/*@
    predicate valid_range(integer x) = 2 <= x <= 100;
    
    logic integer compute_result(integer a, integer b) = a * b - a - b + 1;
    
    lemma result_positive: \forall integer a, b; valid_range(a) && valid_range(b) ==> compute_result(a, b) > 0;
    lemma multiplication_bounds: \forall integer a, b; valid_range(a) && valid_range(b) ==> 4 <= a * b <= 10000;
    lemma multiplication_ge_sum: \forall integer a, b; valid_range(a) && valid_range(b) ==> a * b >= a + b;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == compute_result(a, b);
    ensures \result > 0;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t ret;
    
    //@ assert 2 <= a && a <= 100;
    //@ assert 2 <= b && b <= 100;
    //@ assert 4 <= a * b <= 10000;
    //@ assert a * b >= a + b;
    
    ret = a * b - a - b + 1;
    
    //@ assert ret == compute_result(a, b);
    //@ assert ret > 0;
    
    return ret;
}
