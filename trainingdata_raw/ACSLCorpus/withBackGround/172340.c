#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer result_value(integer a) = a + square(a) + cube(a);

    lemma square_bound:
        \forall integer a; valid_range(a) ==> square(a) <= 100;

    lemma cube_bound:
        \forall integer a; valid_range(a) ==> 1 <= cube(a) <= 1000;
*/

/*@
    requires valid_range(a);
    ensures \result == result_value(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t a_squared;
    uint32_t a_cubed;
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert square(a) <= 100;
    a_squared = a * a;

    //@ assert 1 <= cube(a) && cube(a) <= 1000;
    a_cubed = a * a * a;

    result = a + a_squared + a_cubed;
    //@ assert result == result_value(a);
    return result;
}
