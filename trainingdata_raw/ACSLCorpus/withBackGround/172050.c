#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 10;
    
    logic integer compute_result(integer a) = a + a * a + a * a * a;
    
    lemma square_bounds:
        \forall integer a; is_valid_range(a) ==> 1 <= a * a <= 100;
    
    lemma cube_bounds:
        \forall integer a; is_valid_range(a) ==> 1 <= a * a * a <= 1000;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    int64_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == a + a * a + a * a * a;
    
    return result;
}
