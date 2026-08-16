#include <stdint.h>

/*@
    predicate valid_params(integer A, integer B, integer H) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100 &&
        1 <= H && H <= 100 &&
        H % 2 == 0;

    logic integer expected_result(integer A, integer B, integer H) =
        (A + B) * H / 2;

    lemma sum_bounds: \forall integer A, B; 1 <= A <= 100 && 1 <= B <= 100 ==> A + B <= 200;
    lemma product_bounds: \forall integer A, B, H; 1 <= A <= 100 && 1 <= B <= 100 && 1 <= H <= 100 ==> (A + B) * H <= 20000;
*/

/*@
    requires valid_params(A, B, H);
    ensures \result == expected_result(A, B, H);
    assigns \nothing;
*/
uint64_t func(uint64_t A, uint64_t B, uint64_t H)
{
    uint64_t sum;
    uint64_t result;
    uint64_t temp_sum;
    uint64_t count;

    sum = A + B;
    result = 0;
    
    //@ assert sum <= 200;
    
    temp_sum = sum * H;
    count = 0;
    
    /*@
        loop invariant 1 <= A <= 100;
        loop invariant 1 <= B <= 100;
        loop invariant 1 <= H <= 100;
        loop invariant H % 2 == 0;
        loop invariant sum == A + B;
        loop invariant temp_sum >= 0;
        loop invariant temp_sum == sum * H - 2 * result;
        loop invariant result >= 0;
        loop invariant result <= (sum * H) / 2;
        loop assigns temp_sum, result;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        result += 1;
    }
    
    //@ assert result == (A + B) * H / 2;
    return result;
}
