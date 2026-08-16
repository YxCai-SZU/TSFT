#include <stdint.h>

/*@
    predicate valid_range(integer a, integer p) =
        0 <= a <= 100 && 0 <= p <= 100;

    logic integer compute_initial(integer a, integer p) = a * 3 + p;

    lemma result_bounds:
        \forall integer a, p, result;
        valid_range(a, p) && result == compute_initial(a, p) / 2 ==>
        (a + p) / 2 <= result <= compute_initial(a, p);
*/

/*@
    requires valid_range(a, p);
    ensures \result <= compute_initial(a, p);
    ensures \result >= (a + p) / 2;
*/
uint32_t func(uint32_t a, uint32_t p)
{
    uint32_t result;
    uint32_t quotient;
    uint32_t remainder;

    result = a * 3 + p;
    quotient = 0;
    remainder = result;

    /*@
        loop invariant remainder == result - 2 * quotient;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant result == compute_initial(a, p);
        loop invariant valid_range(a, p);
        loop invariant quotient <= result / 2;
        loop assigns quotient, remainder;
    */
    while (remainder >= 2)
    {
        quotient += 1;
        remainder -= 2;
    }

    result = quotient;

    //@ assert result == compute_initial(a, p) / 2;
    //@ assert result >= (a + p) / 2;

    return result;
}
