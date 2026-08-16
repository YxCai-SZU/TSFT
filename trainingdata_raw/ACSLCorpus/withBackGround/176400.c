#include <stdint.h>

/*@
    predicate quotient_500_invariant(uint32_t x, uint32_t remainder_500, uint32_t quotient_500) =
        0 <= remainder_500 <= x &&
        remainder_500 == x - 500 * quotient_500 &&
        quotient_500 <= x / 500;

    predicate quotient_5_invariant(uint32_t x, uint32_t remainder_5, uint32_t quotient_5) =
        0 <= remainder_5 <= x &&
        remainder_5 == x - 5 * quotient_5 &&
        quotient_5 <= x / 5;

    lemma quotient_500_decreases:
        \forall uint32_t x, remainder_500, quotient_500;
        quotient_500_invariant(x, remainder_500, quotient_500) && remainder_500 >= 500 ==>
        remainder_500 - 500 < remainder_500;

    lemma quotient_5_decreases:
        \forall uint32_t x, remainder_5, quotient_5;
        quotient_5_invariant(x, remainder_5, quotient_5) && remainder_5 >= 5 ==>
        remainder_5 - 5 < remainder_5;
*/

/*@
    requires 1 <= x <= 100000;
    ensures \result == 1000 * (x / 500) + 5 * (x % 500 / 5);
*/
uint32_t func(uint32_t x)
{
    uint32_t x_local;
    uint32_t result;
    uint32_t quotient_500;
    uint32_t remainder_500;
    uint32_t quotient_5;
    uint32_t remainder_5;
    
    x_local = x;
    result = 0;
    quotient_500 = 0;
    remainder_500 = x_local;

    //@ assert quotient_500_invariant(x_local, remainder_500, quotient_500);
    /*@
        loop invariant quotient_500_invariant(x_local, remainder_500, quotient_500);
        loop assigns remainder_500, quotient_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 == x_local - 500 * quotient_500;
        remainder_500 = remainder_500 - 500;
        quotient_500 = quotient_500 + 1;
        //@ assert quotient_500_invariant(x_local, remainder_500, quotient_500);
    }
    //@ assert remainder_500 == x_local % 500;
    //@ assert quotient_500 == x_local / 500;
    result = result + 1000 * quotient_500;
    x_local = remainder_500;

    quotient_5 = 0;
    remainder_5 = x_local;

    //@ assert quotient_5_invariant(x_local, remainder_5, quotient_5);
    /*@
        loop invariant quotient_5_invariant(x_local, remainder_5, quotient_5);
        loop assigns remainder_5, quotient_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 == x_local - 5 * quotient_5;
        remainder_5 = remainder_5 - 5;
        quotient_5 = quotient_5 + 1;
        //@ assert quotient_5_invariant(x_local, remainder_5, quotient_5);
    }
    //@ assert remainder_5 == x_local % 5;
    //@ assert quotient_5 == x_local / 5;
    result = result + 5 * quotient_5;
    x_local = remainder_5;

    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);
    return result;
}
