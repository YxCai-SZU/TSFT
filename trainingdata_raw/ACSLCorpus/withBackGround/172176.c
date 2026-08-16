#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer initial_product(integer r) = 2 * 31415 * r;

    lemma product_bounds: \forall integer r; valid_range(r) ==> 
        2 * 31415 <= initial_product(r) <= 2 * 31415 * 100;

    lemma division_property: \forall integer r, integer q, integer rem; 
        valid_range(r) && q >= 0 && rem >= 0 && rem + q * 10000 == initial_product(r) ==> 
        q * 10000 + rem == initial_product(r);
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * 31415 * r / 10000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t quotient = 0;
    const int64_t divisor = 10000;

    // Precondition verification
    //@ assert 1 <= r <= 100;

    // Overflow prevention check
    //@ assert 2 * 31415 <= 100000;

    result = 2 * 31415 * r;

    // Initial bounds verification
    //@ assert 2 * 31415 * 1 <= result <= 2 * 31415 * 100;

    /*@
        loop invariant 1 <= r <= 100;
        loop invariant result >= 0;
        loop invariant result <= 2 * 31415 * 100;
        loop invariant quotient >= 0;
        loop invariant result + quotient * divisor == 2 * 31415 * r;
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor)
    {
        result -= divisor;
        quotient += 1;
    }

    // Final verification of division property
    //@ assert quotient * 10000 + result == 2 * 31415 * r;

    return quotient;
}
