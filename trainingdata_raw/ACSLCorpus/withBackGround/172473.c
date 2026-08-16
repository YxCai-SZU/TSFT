#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B, integer H) =
        1 <= A <= 100 &&
        1 <= B <= 100 &&
        1 <= H <= 100 &&
        H % 2 == 0;

    logic integer calculate_result(integer A, integer B, integer H) =
        (A + B) * H / 2;

    lemma sum_bounds:
        \forall integer A, B;
        valid_input(A, B, 1) ==> 2 <= A + B <= 200;

    lemma product_bounds:
        \forall integer A, B, H;
        valid_input(A, B, H) ==> (A + B) * H <= 20000;
*/

/*@
    requires valid_input(A, B, H);
    ensures \result == calculate_result(A, B, H);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t B, uint32_t H)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t product;
    uint32_t result;

    //@ assert 2 <= A + B <= 200;
    sum = A + B;

    //@ assert sum * H <= 20000;
    product = sum * H;

    result = product / 2;
    //@ assert result == (A + B) * H / 2;
    return result;
}
