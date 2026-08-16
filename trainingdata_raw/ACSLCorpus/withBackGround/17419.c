#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;

    logic integer a_squared(integer a) = a * a;
    logic integer a_cubed(integer a) = a * a * a;
    logic integer expected_result(integer a) = a + a_squared(a) + a_cubed(a);

    lemma a_squared_bound: \forall integer a; is_valid_a(a) ==> a_squared(a) <= 100;
    lemma a_cubed_bound: \forall integer a; is_valid_a(a) ==> a_cubed(a) <= 1000;
    lemma result_bound: \forall integer a; is_valid_a(a) ==> expected_result(a) <= 1110;
*/

/*@
    requires is_valid_a(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
uint64_t func(uint64_t a)
{
    // Declare all variables at the top
    uint64_t a_2;
    uint64_t a_3;
    uint64_t result;

    //@ assert a * a <= 100;
    a_2 = a * a;

    //@ assert a * a * a <= 1000;
    a_3 = a * a * a;

    //@ assert a + a_2 + a_3 <= 1110;
    result = a + a_2 + a_3;

    return result;
}
