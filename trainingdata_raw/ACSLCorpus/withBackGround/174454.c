#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        0 <= a && a <= 10000 && 0 <= b && b <= 10000;

    logic integer safe_product(integer a, integer b) = a * b;

    logic integer expected_result(integer a, integer b) = (a * b) / 100;

    lemma product_bounds:
        \forall integer a, b;
            valid_input(a, b) ==> 0 <= safe_product(a, b) <= 10000 * 10000;
*/

/*@
    requires valid_input(a, b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t product;
    uint32_t quotient = 0;
    uint32_t remainder;

    //@ assert valid_input(a, b);
    
    product = a * b;
    remainder = product;

    //@ assert 0 <= product <= 10000 * 10000;

    /*@
        loop invariant 0 <= quotient <= expected_result(a, b);
        loop invariant remainder == safe_product(a, b) - quotient * 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        remainder -= 100;
        quotient += 1;
    }

    //@ assert quotient == expected_result(a, b);
    return quotient;
}
