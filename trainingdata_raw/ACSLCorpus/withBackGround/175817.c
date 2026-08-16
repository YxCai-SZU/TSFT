#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 10;

    logic integer target_result(integer a, integer b, integer c) =
        (a * b * c + a * b) / 2;

    lemma bounds_product_abc:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= a * b * c <= 1000;

    lemma bounds_product_ab:
        \forall integer a, b;
            valid_range(a) && valid_range(b) ==>
            1 <= a * b <= 100;

    lemma bounds_sum:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            2 <= a * b * c + a * b <= 1100;

    lemma result_bound:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            1 <= target_result(a, b, c) <= 550;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c);
    ensures \result == target_result(a, b, c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    //@ assert 1 <= a * b * c <= 1000;
    //@ assert 1 <= a * b <= 100;
    //@ assert 2 <= a * b * c + a * b <= 1100;
    //@ assert 1 <= (a * b * c + a * b) / 2 <= 550;

    result = (a * b * c + a * b) / 2;

    //@ assert result == target_result(a, b, c);
    return result;
}
