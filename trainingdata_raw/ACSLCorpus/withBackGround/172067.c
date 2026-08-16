#include <stdint.h>

/*@
    predicate is_valid_input(integer x) = 1 <= x <= 1000000000;

    logic integer compute_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma result_lemma:
        \forall integer x; is_valid_input(x) ==>
            compute_result(x) == (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires is_valid_input(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t x_500;
    uint64_t x_5;
    uint64_t result;

    x_500 = x / 500;
    //@ assert x_500 == x / 500;

    x_5 = (x % 500) / 5;
    //@ assert x_5 == (x % 500) / 5;

    result = x_500 * 1000 + x_5 * 5;
    //@ assert result == compute_result(x);

    return result;
}
