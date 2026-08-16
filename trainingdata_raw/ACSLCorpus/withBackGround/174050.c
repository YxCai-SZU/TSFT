#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100000000000000000;

    logic integer compute_result(integer x) =
        (x / 11) * 2 + (x % 11 + 5) / 6;

    lemma quotient_bounds:
        \forall integer x; valid_range(x) ==> 0 <= (x / 11) * 2 <= 2 * 100000000000000000;

    lemma remainder_bounds:
        \forall integer x; valid_range(x) ==> 0 <= (x % 11 + 5) / 6 <= (11 + 5) / 6;

    lemma result_correct:
        \forall integer x; valid_range(x) ==> 
            compute_result(x) == (x / 11) * 2 + (x % 11 + 5) / 6;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t quotient;
    uint64_t remainder;
    uint64_t result;

    quotient = x / 11;
    remainder = x % 11;
    result = quotient * 2;

    //@ assert quotient == x / 11;
    //@ assert remainder == x % 11;
    //@ assert result == quotient * 2;

    if (remainder + 5 >= 6)
    {
        result = result + (remainder + 5) / 6;
        //@ assert result == quotient * 2 + (remainder + 5) / 6;
    }

    //@ assert 0 <= quotient * 2 <= 2 * 100000000000000000;
    //@ assert 0 <= (remainder + 5) / 6 <= (11 + 5) / 6;
    //@ assert result == (x / 11) * 2 + (x % 11 + 5) / 6;

    return result;
}
