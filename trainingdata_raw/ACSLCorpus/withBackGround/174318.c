#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= b <= 100;

    logic integer scaled_a(integer x) = x * 8 / 100;
    logic integer scaled_b(integer x) = x * 10 / 100;

    lemma loop_invariant_maintained:
        \forall integer a, b, x;
            valid_range(a, b) && 1 <= x <= 1000 ==>
            (scaled_a(x) == a && scaled_b(x) == b) ==>
            x * 8 / 100 == a && x * 10 / 100 == b;
*/

/*@
    requires 1 <= a <= b <= 100;
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==>
        (uint32_t)\result * 8 / 100 == a &&
        (uint32_t)\result * 10 / 100 == b;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t x;
    int32_t result;

    //@ assert valid_range(a, b);
    x = 1;
    result = -1;

    /*@
        loop invariant 1 <= a <= b <= 100;
        loop invariant 1 <= x <= 1001;
        loop invariant result == -1;
        loop invariant \forall integer i; 1 <= i < x ==>
            i * 8 / 100 != a || i * 10 / 100 != b;
        loop assigns x, result;
        loop variant 1001 - x;
    */
    while (x <= 1000)
    {
        uint32_t ax = x * 8 / 100;
        uint32_t bx = x * 10 / 100;

        //@ assert ax == scaled_a(x);
        //@ assert bx == scaled_b(x);

        if (ax == a && bx == b)
        {
            result = (int32_t)x;
            //@ assert result >= 0;
            break;
        }

        //@ assert scaled_a(x) != a || scaled_b(x) != b;
        x = x + 1;
    }

    //@ assert result >= 0 || result == -1;
    return result;
}
