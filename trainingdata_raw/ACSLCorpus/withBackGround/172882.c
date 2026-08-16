#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer expected_result(integer a) = a + square(a) + cube(a);

    lemma square_bound: \forall integer a; valid_range(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; valid_range(a) ==> cube(a) <= 1000;
    lemma sum_bound: \forall integer a; valid_range(a) ==> a + square(a) + cube(a) <= 18446744073709551615;
*/

/*@
    requires valid_range(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    uint64_t a1;
    uint64_t a2;
    uint64_t a3;
    uint64_t result;

    a1 = a;

    //@ assert square(a) <= 100;
    a2 = a * a;

    //@ assert cube(a) <= 1000;
    a3 = a * a * a;

    //@ assert a1 + a2 + a3 <= 18446744073709551615;
    result = a1 + a2 + a3;

    return result;
}
