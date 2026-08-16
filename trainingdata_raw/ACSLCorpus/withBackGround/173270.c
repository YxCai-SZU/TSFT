#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;

    logic integer multiplier(integer x, integer k) = x * k;

    lemma multiplier_zero: \forall integer x, k; k == 0 ==> multiplier(x, k) == 0;
    lemma multiplier_one: \forall integer x, k; k == 1 ==> multiplier(x, k) == x;
    lemma multiplier_two: \forall integer x, k; k == 2 ==> multiplier(x, k) == x * 2;

    logic integer square(integer k) = k * k;

    lemma square_zero: \forall integer k; k == 0 ==> square(k) == 0;
    lemma square_one: \forall integer k; k == 1 ==> square(k) == 1;
    lemma square_two: \forall integer k; k == 2 ==> square(k) == 4;
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    ensures \result == a * b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    //@ assert a * b <= 10000;
    return a * b;
}
