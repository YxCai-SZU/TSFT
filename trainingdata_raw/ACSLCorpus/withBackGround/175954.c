#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer div_100(integer x) = x / 100;
    logic integer div_10(integer x) = x / 10;

    lemma div_100_positive: \forall integer x; x >= 0 ==> div_100(x) >= 0;
    lemma div_10_positive: \forall integer x; x >= 0 ==> div_10(x) >= 0;
*/

/*@
    requires valid_params(a, b);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> div_100(\result * 8) == a && div_10(\result * 10) == b;
    assigns \nothing;
*/
int32_t func(uint64_t a, uint64_t b)
{
    uint64_t i = 0;
    /*@
        loop invariant 0 <= i <= 1000000;
        loop invariant valid_params(a, b);
        loop assigns i;
        loop variant 1000000 - i;
    */
    while (i < 1000000)
    {
        uint64_t x = i * 8;
        uint64_t a_compare = a * 100;
        uint64_t b_compare = b * 10;
        uint64_t x_div_100 = 0;
        uint64_t a_div_100 = 0;
        uint64_t b_div_10 = 0;

        /*@
            loop invariant x >= 0;
            loop invariant x_div_100 >= 0;
            loop invariant x == i * 8 - x_div_100 * 100;
            loop assigns x, x_div_100;
            loop variant x;
        */
        while (x >= 100)
        {
            x -= 100;
            x_div_100 += 1;
        }

        /*@
            loop invariant a_compare >= 0;
            loop invariant a_div_100 >= 0;
            loop invariant a_compare == a * 100 - a_div_100 * 100;
            loop assigns a_compare, a_div_100;
            loop variant a_compare;
        */
        while (a_compare >= 100)
        {
            a_compare -= 100;
            a_div_100 += 1;
        }

        /*@
            loop invariant b_compare >= 0;
            loop invariant b_div_10 >= 0;
            loop invariant b_compare == b * 10 - b_div_10 * 10;
            loop assigns b_compare, b_div_10;
            loop variant b_compare;
        */
        while (b_compare >= 10)
        {
            b_compare -= 10;
            b_div_10 += 1;
        }

        //@ assert x_div_100 == a_div_100 ==> div_100(i * 8) == a;
        
        if (x_div_100 == a_div_100 && i * 10 / 10 == b_div_10)
        {
            return (int32_t)i;
        }
        i += 1;
    }
    return -1;
}
