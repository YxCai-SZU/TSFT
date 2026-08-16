#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;
    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer result_value(integer a) = a + square(a) + cube(a);
    
    lemma square_bound: \forall integer a; is_valid_a(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; is_valid_a(a) ==> cube(a) <= 1000;
*/

/*@
    requires is_valid_a(a);
    ensures \result == result_value(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a_1;
    uint32_t a_2;
    uint32_t a_3;
    uint32_t ans;
    
    a_1 = a;
    
    //@ assert is_valid_a(a);
    //@ assert square(a) <= 100;
    a_2 = a * a;
    
    //@ assert is_valid_a(a);
    //@ assert cube(a) <= 1000;
    a_3 = a * a * a;
    
    ans = a_1 + a_2 + a_3;
    
    //@ assert ans == result_value(a);
    return ans;
}
