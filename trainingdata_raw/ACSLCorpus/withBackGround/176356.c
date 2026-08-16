#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer func_result(integer a) = a + square(a) + cube(a);
    
    lemma square_bound: \forall integer a; valid_range(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; valid_range(a) ==> cube(a) <= 1000;
    lemma result_bound: \forall integer a; valid_range(a) ==> func_result(a) <= 1331;
*/

/*@
    requires valid_range(a);
    ensures \result == func_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t result;
    
    //@ assert valid_range(a);
    
    a1 = a;
    
    //@ assert square(a) <= 100;
    a2 = a * a;
    
    //@ assert cube(a) <= 1000;
    a3 = a * a * a;
    
    //@ assert func_result(a) <= 1331;
    result = a1 + a2 + a3;
    
    //@ assert result == func_result(a);
    return result;
}
