#include <stdint.h>

/*@
    predicate is_valid_range(integer a) = 1 <= a <= 100;

    logic integer multiply(integer a, integer multiplier) = a * multiplier;
    logic integer divide_floor(integer a, integer multiplier, integer divisor) = 
        (a * multiplier) / divisor;

    lemma multiplication_bounds:
        \forall integer a, multiplier;
        is_valid_range(a) && multiplier == 6283185307 ==>
        1 <= multiply(a, multiplier) <= 100 * 6283185307;
*/

/*@
    requires is_valid_range(a);
    ensures \result == divide_floor(a, 6283185307, 1000000000);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t multiplier;
    int64_t result;
    int64_t temp;
    int64_t divisor;
    int64_t quotient;
    int64_t remainder;

    multiplier = 6283185307;
    result = 0;
    //@ assert is_valid_range(a);
    //@ assert multiplier == 6283185307;
    //@ assert 1 <= multiply(a, multiplier) <= 100 * 6283185307;
    temp = a * multiplier;

    divisor = 1000000000;
    quotient = 0;
    remainder = 0;

    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= quotient;
        loop invariant 0 <= temp;
        loop invariant temp == multiply(a, multiplier) - quotient * divisor;
        loop invariant multiply(a, multiplier) == 6283185307 * a;
        loop invariant divisor == 1000000000;
        loop assigns temp, quotient;
        loop variant temp;
    */
    while (temp >= divisor)
    {
        temp -= divisor;
        quotient += 1;
    }
    remainder = temp;

    if (a < 0)
    {
        quotient = -quotient;
    }

    result = quotient;
    //@ assert result == divide_floor(a, 6283185307, 1000000000);
    return result;
}
