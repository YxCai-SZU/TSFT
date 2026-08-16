#include <stdint.h>

/*@
    predicate is_valid_l(integer l) = 1 <= l && l <= 1000;

    logic integer compute_expected(integer l) = (l * 3) / 5;

    lemma multiplication_bound: \forall integer l; is_valid_l(l) ==> l * 3 <= 3000;
*/

/*@
    requires is_valid_l(l);
    ensures \result == compute_expected(l);
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t quotient;
    int64_t divisor;

    //@ assert is_valid_l(l);
    //@ assert l * 3 <= 3000;

    result = l * 3;
    quotient = 0;
    divisor = 5;

    /*@
        loop invariant 0 <= result;
        loop invariant result == l * 3 - quotient * divisor;
        loop invariant is_valid_l(l);
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor)
    {
        result -= divisor;
        quotient += 1;
    }

    //@ assert quotient == compute_expected(l);
    return quotient;
}
