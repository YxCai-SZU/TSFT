#include <stdint.h>

/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 10;

    logic integer a_squared(integer a) = a * a;
    logic integer a_cubed(integer a) = a * a * a;
    logic integer target_result(integer a) = a + a_squared(a) + a_cubed(a);

    lemma a_squared_range: \forall integer a; is_valid_a(a) ==> 1 <= a_squared(a) && a_squared(a) <= 100;
    lemma a_cubed_range: \forall integer a; is_valid_a(a) ==> 1 <= a_cubed(a) && a_cubed(a) <= 1000;
    lemma result_bound: \forall integer a; is_valid_a(a) ==> a + a_squared(a) + a_cubed(a) <= 1110;
*/

/*@
    requires is_valid_a(a);
    ensures \result == target_result(a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t res;

    a1 = a;
    //@ assert a1 == a;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a && a * a <= 100;
    a2 = a * a;
    //@ assert a2 == a * a;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a3 = a * a * a;
    //@ assert a3 == a * a * a;

    //@ assert a1 <= 10;
    //@ assert a2 <= 100;
    //@ assert a3 <= 1000;
    //@ assert a1 + a2 + a3 <= 1110;

    res = a1 + a2 + a3;
    //@ assert res == a + a * a + a * a * a;
    return res;
}
