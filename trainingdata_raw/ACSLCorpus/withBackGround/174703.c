#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a && a <= 10000 &&
        1 <= b && b <= 10000;

    logic integer product_mod2(integer a, integer b) =
        (a * b) % 2;

    lemma product_bound: \forall integer a, b;
        valid_inputs(a, b) ==> a * b <= 10000 * 10000;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == product_mod2(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t c;
    int32_t temp;
    int32_t is_even;

    //@ assert valid_inputs(a, b);
    //@ assert a * b <= 10000 * 10000;

    c = a * b;
    is_even = 1;
    temp = (int32_t)c;

    /*@
        loop invariant 1 <= a && a <= 10000;
        loop invariant 1 <= b && b <= 10000;
        loop invariant 0 <= temp && temp <= c;
        loop invariant temp % 2 == c % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }

    /*@
        loop invariant 1 <= a && a <= 10000;
        loop invariant 1 <= b && b <= 10000;
        loop invariant -2 <= temp && temp < 2;
        loop invariant temp % 2 == c % 2;
        loop assigns temp;
        loop variant -temp;
    */
    while (temp < 0)
    {
        temp += 2;
    }

    if (temp == 1)
    {
        is_even = 0;
    }

    if (is_even)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
