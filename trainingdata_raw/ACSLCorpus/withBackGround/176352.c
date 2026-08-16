#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 10;

    logic integer a_pow_2(integer a) = a * a;
    logic integer a_pow_3(integer a) = a * a * a;
    logic integer expected_result(integer a) = a + a_pow_2(a) + a_pow_3(a);

    lemma pow2_bound: \forall integer a; is_valid_range(a) ==> a_pow_2(a) <= 100;
    lemma pow3_bound: \forall integer a; is_valid_range(a) ==> a_pow_3(a) <= 1000;
    lemma sum_bound: \forall integer a; is_valid_range(a) ==> a + a_pow_2(a) + a_pow_3(a) <= 1110;
*/

/*@
    requires is_valid_range(a);
    ensures \result == expected_result(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    uint64_t a_unsigned;
    uint64_t a_pow_2;
    uint64_t a_pow_3;
    uint64_t sum;

    //@ assert is_valid_range(a);
    a_unsigned = (uint64_t)a;

    //@ assert a_unsigned >= 1 && a_unsigned <= 10;
    //@ assert a_unsigned * a_unsigned <= 100;
    a_pow_2 = a_unsigned * a_unsigned;

    //@ assert a_unsigned * a_unsigned * a_unsigned <= 1000;
    a_pow_3 = a_pow_2 * a_unsigned;

    //@ assert a_unsigned + a_pow_2 <= 110;
    //@ assert a_unsigned + a_pow_2 + a_pow_3 <= 1110;
    sum = a_unsigned + a_pow_2 + a_pow_3;

    return (int64_t)sum;
}
