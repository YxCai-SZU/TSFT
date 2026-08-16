#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer func_spec(integer a) = a + a * a + a * a * a;
    
    lemma square_bound: \forall integer a; a_in_range(a) ==> a * a <= 100;
    lemma cube_lower_bound: \forall integer a; a_in_range(a) ==> a * a * a >= 1;
    lemma cube_upper_bound: \forall integer a; a_in_range(a) ==> a * a * a <= 1000;
    lemma sum_bound: \forall integer a; a_in_range(a) ==> a + a * a + a * a * a <= 1111;
*/

/*@
    requires a_in_range(a);
    ensures \result == func_spec(a);
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert a >= 1 && a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a >= 1;
    //@ assert a * a * a <= 1000;
    //@ assert a + a * a + a * a * a <= 1111;
    
    result = a + a * a + a * a * a;
    
    //@ assert result == func_spec(a);
    return result;
}
