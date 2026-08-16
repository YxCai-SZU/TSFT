#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;

    lemma mult_bound1: \forall integer a; a_in_range(a) ==> 800 * a <= 800 * 100;
    lemma mult_bound2: \forall integer a; a_in_range(a) ==> 200 * (a / 15) <= 200 * 7;
    lemma result_nonneg: \forall integer a; a_in_range(a) ==> 800 * a - ((a / 15) * 200) >= 0;
*/

/*@
    requires a_in_range(a);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(uint32_t a)
{
    int32_t result;
    
    //@ assert a_in_range(a);
    //@ assert 800 * a <= 800 * 100;
    //@ assert 200 * (a / 15) <= 200 * 7;
    
    result = 800 * (int32_t)a - (((int32_t)(a / 15)) * 200);
    
    //@ assert result >= 0;
    return result;
}
