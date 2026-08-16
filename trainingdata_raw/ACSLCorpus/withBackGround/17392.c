#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    
    lemma a_square_bounds: 
        \forall integer a; is_valid_a(a) ==> 1 <= a * a && a * a <= 100;
    
    lemma a_cube_bounds: 
        \forall integer a; is_valid_a(a) ==> 1 <= a * a * a && a * a * a <= 1000;
*/

/*@
    requires is_valid_a(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int32_t func(uint32_t a) {
    int32_t a_;
    int32_t a2_;
    int32_t a3_;
    int32_t result;
    
    a_ = (int32_t)a;
    
    //@ assert 1 <= a_ && a_ <= 10;
    
    //@ assert 1 <= a_ * a_ && a_ * a_ <= 100;
    
    //@ assert 1 <= a_ * a_ * a_ && a_ * a_ * a_ <= 1000;
    
    a2_ = a_ * a_;
    a3_ = a_ * a_ * a_;
    result = a_ + a2_ + a3_;
    
    //@ assert result == compute_result(a);
    
    return result;
}
