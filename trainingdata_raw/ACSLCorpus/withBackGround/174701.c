#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    
    lemma a_square_bounds:
        \forall integer a; valid_range(a) ==> 1 <= a * a <= 100;
    
    lemma a_cube_bounds:
        \forall integer a; valid_range(a) ==> 1 <= a * a * a <= 1000;
    
    lemma result_bounds:
        \forall integer a; valid_range(a) ==> 3 <= compute_result(a) <= 1110;
*/

/*@
    requires valid_range(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a) {
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t ans;
    
    a1 = a;
    
    //@ assert a1 >= 1;
    //@ assert a1 <= 10;
    
    //@ assert a * a >= 1;
    //@ assert a * a <= 100;
    a2 = a * a;
    
    //@ assert a * a * a >= 1;
    //@ assert a * a * a <= 1000;
    a3 = a * a * a;
    
    ans = a1 + a2 + a3;
    
    //@ assert ans >= 3;
    //@ assert ans <= 1110;
    
    return ans;
}
