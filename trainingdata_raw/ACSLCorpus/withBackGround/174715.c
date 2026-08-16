#include <stdint.h>

/*@
    predicate valid_input(integer x) = 1 <= x <= 100000;

    logic integer number_500(integer x) = x / 500;
    logic integer remainder(integer x) = x % 500;
    logic integer number_5(integer x) = (x % 500) / 5;
    logic integer expected_result(integer x) = 
        1000 * number_500(x) + 5 * number_5(x);

    lemma remainder_definition: 
        \forall integer x; valid_input(x) ==> remainder(x) == x % 500;
    lemma number_5_definition: 
        \forall integer x; valid_input(x) ==> number_5(x) == (x % 500) / 5;
    lemma result_correctness: 
        \forall integer x; valid_input(x) ==> 
            expected_result(x) == 1000 * (x / 500) + 5 * ((x % 500) / 5);
*/

/*@
    requires valid_input(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x) {
    uint32_t number_500;
    uint32_t remain;
    uint32_t number_5;
    uint32_t result;

    number_500 = x / 500;
    remain = x % 500;
    number_5 = remain / 5;

    //@ assert remain == x % 500;
    //@ assert number_5 == (x % 500) / 5;
    //@ assert number_500 == x / 500;

    result = 1000 * number_500 + 5 * number_5;
    //@ assert result == 1000 * (x / 500) + 5 * ((x % 500) / 5);

    return result;
}
