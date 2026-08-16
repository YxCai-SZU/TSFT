#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    
    lemma result_bound: \forall integer a; is_valid_range(a) ==> compute_result(a) <= 1331;
*/

/*@
    requires is_valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a) {
    int32_t a_i32;
    int32_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert a + a * a + a * a * a <= 1331;
    
    a_i32 = (int32_t)a;
    
    result = a_i32 + a_i32 * a_i32 + a_i32 * a_i32 * a_i32;
    
    return result;
}
