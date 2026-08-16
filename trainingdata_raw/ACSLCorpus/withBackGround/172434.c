#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    
    lemma pow2_bounds:
        \forall integer a; is_valid_a(a) ==> 1 <= a * a <= 100;
    
    lemma pow3_bounds:
        \forall integer a; is_valid_a(a) ==> 1 <= a * a * a <= 1000;
*/

/*@
    requires is_valid_a(a);
    ensures \result == compute_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t a_pow_2;
    int64_t a_pow_3;
    int64_t result;
    
    //@ assert is_valid_a(a);
    
    //@ assert 1 <= a * a <= 100;
    a_pow_2 = a * a;
    
    //@ assert 1 <= a * a * a <= 1000;
    a_pow_3 = a_pow_2 * a;
    
    result = a + a_pow_2 + a_pow_3;
    
    //@ assert result == compute_result(a);
    return result;
}
