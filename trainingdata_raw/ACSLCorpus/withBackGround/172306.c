#include <stdint.h>

/*@
    predicate valid_s(integer s) = 1 <= s <= 100;

    logic integer compute_result(integer s) = (s * 100) / 200;

    lemma result_lemma:
        \forall integer s; valid_s(s) ==> compute_result(s) == (s * 100) / 200;
*/

/*@
    requires valid_s(s);
    ensures \result == compute_result(s);
    assigns \nothing;
*/
int32_t func(uint32_t s)
{
    int32_t x;
    int32_t quotient;
    int32_t remainder;
    int32_t divisor;
    
    x = (int32_t)(s * 100);
    quotient = 0;
    remainder = x;
    divisor = 200;

    /*@
        loop invariant 1 <= s <= 100;
        loop invariant quotient * divisor + remainder == x;
        loop invariant 0 <= remainder;
        loop invariant quotient >= 0;
        loop assigns remainder, quotient;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }

    //@ assert quotient == compute_result(s);
    return quotient;
}
