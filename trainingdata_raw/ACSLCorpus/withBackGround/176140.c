#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer total(integer a) = a + square(a) + cube(a);

    lemma square_bound: \forall integer a; valid_range(a) ==> 1 <= square(a) <= 100;
    lemma cube_bound: \forall integer a; valid_range(a) ==> 1 <= cube(a) <= 1000;
    lemma total_bound: \forall integer a; valid_range(a) ==> total(a) <= 1111;
*/

/*@
    requires valid_range(a);
    ensures \result == total(a);
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    //@ assert valid_range(a);
    
    //@ assert 1 <= a * a <= 100;
    //@ assert 1 <= a * a * a <= 1000;
    //@ assert a + (a * a) + (a * a * a) <= 1111;
    
    return a + (a * a) + (a * a * a);
}
