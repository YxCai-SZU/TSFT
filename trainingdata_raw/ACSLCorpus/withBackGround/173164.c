#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer func_result(integer a) = a + square(a) + cube(a);
    
    lemma square_bounds: \forall integer a; a_in_range(a) ==> 1 <= square(a) <= 100;
    lemma cube_bounds: \forall integer a; a_in_range(a) ==> 1 <= cube(a) <= 1000;
    lemma no_overflow: \forall integer a; a_in_range(a) ==> func_result(a) <= 1110;
*/

/*@
    requires a_in_range(a);
    ensures \result == func_result(a);
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    //@ assert a_in_range(a);
    
    int32_t a_2;
    int32_t a_3;
    int32_t result;
    
    //@ assert 1 <= a * a <= 100;
    a_2 = a * a;
    
    //@ assert 1 <= a * a * a <= 1000;
    a_3 = a * a * a;
    
    //@ assert a + a_2 + a_3 == func_result(a);
    result = a + a_2 + a_3;
    
    return result;
}
