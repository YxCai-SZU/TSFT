#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;
    
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer target_result(integer a) = a + square(a) + cube(a);
*/

/*@
    requires valid_range(a);
    ensures \result == target_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a1;
    uint32_t a2;
    uint32_t result;
    
    //@ assert valid_range(a);
    a1 = a;
    
    //@ assert 1 <= a1 && a1 <= 10;
    
    //@ assert square(a) <= 100;
    //@ assert cube(a) <= 1000;
    
    a2 = a * a;
    
    //@ assert 1 <= a2 && a2 <= 100;
    //@ assert a2 == square(a);
    
    //@ assert a2 * a <= 1000;
    //@ assert a2 * a == cube(a);
    
    //@ assert a1 + a2 + a2 * a <= 1110;
    //@ assert a1 + a2 + a2 * a == target_result(a);
    
    result = a1 + a2 + a2 * a;
    return result;
}

/*@
    lemma square_bound: \forall integer a; valid_range(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; valid_range(a) ==> cube(a) <= 1000;
    lemma result_bound: \forall integer a; valid_range(a) ==> target_result(a) <= 1110;
*/
