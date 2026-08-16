#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_sum(integer x) = x + (x * x) + (x * x * x);

    logic integer compute_result(integer x) = compute_sum(x) / 3;

    lemma sum_bounds: \forall integer x; valid_range(x) ==> 1 <= compute_sum(x) <= 1110000;
    lemma square_bounds: \forall integer x; valid_range(x) ==> 1 <= x * x <= 10000;
    lemma cube_bounds: \forall integer x; valid_range(x) ==> 1 <= x * x * x <= 1000000;
*/

/*@
    requires 1 <= x <= 100;
    ensures \result == (x + (x * x) + (x * x * x)) / 3;
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;

    //@ assert valid_range(x);
    
    //@ assert 1 <= x * x <= 10000;
    //@ assert 1 <= x * x * x <= 1000000;
    
    result = x + (x * x) + (x * x * x);
    //@ assert result == compute_sum(x);
    
    quotient = 0;
    remainder = result;
    divisor = 3;

    /*@
        loop invariant 1 <= x <= 100;
        loop invariant result == compute_sum(x);
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == result - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient += 1;
        remainder -= divisor;
    }

    //@ assert quotient == compute_result(x);
    return quotient;
}
