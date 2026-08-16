#include <stdint.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer total(integer a) = a + square(a) + cube(a);

    lemma square_bounds: \forall integer a; a_in_range(a) ==> 1 <= square(a) <= 100;
    lemma cube_bounds: \forall integer a; a_in_range(a) ==> 1 <= cube(a) <= 1000;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == a + (a * a) + (a * a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t res;

    //@ assert a_in_range(a);
    
    //@ assert 1 <= a && a <= 10;
    
    //@ assert 1 <= a * a && a * a <= 100;
    
    //@ assert 1 <= a * a * a && a * a * a <= 1000;

    a1 = a;
    a2 = a * a;
    a3 = a * a * a;
    res = a1 + a2 + a3;

    //@ assert res == total(a);
    
    return res;
}
