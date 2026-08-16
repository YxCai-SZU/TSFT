#include <stdint.h>

/*@
    predicate valid_x(integer x) = 1 <= x <= 1000000000;

    logic integer compute_result(integer x) =
        (x / 500 * 1000) + ((x % 500) / 5 * 5);

    lemma result_formula:
        \forall integer x; valid_x(x) ==>
            compute_result(x) == (x / 500 * 1000) + ((x % 500) / 5 * 5);
*/

/*@
    requires valid_x(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t number_500;
    uint64_t remain_x;
    uint64_t number_5;
    uint64_t result;

    //@ assert valid_x(x);

    number_500 = x / 500;
    //@ assert number_500 == x / 500;

    remain_x = x % 500;
    //@ assert remain_x == x % 500;

    number_5 = remain_x / 5;
    //@ assert number_5 == remain_x / 5;

    result = number_500 * 1000 + number_5 * 5;
    //@ assert result == compute_result(x);

    return result;
}
