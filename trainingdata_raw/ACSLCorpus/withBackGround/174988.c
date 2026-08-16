#include <stdint.h>

/*@
    predicate valid_input(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer total_sum(integer A, integer P) = 3 * A + P;

    lemma sum_nonnegative:
        \forall integer A, P; valid_input(A, P) ==> total_sum(A, P) >= 0;
*/

/*@
    requires valid_input(A, P);
    ensures \result >= 0;
*/
int32_t func(uint32_t A, uint32_t P)
{
    uint32_t sum;
    int32_t result;
    uint32_t i;
    uint32_t remaining_sum;

    sum = 3 * A + P;
    result = 0;
    i = 0;
    remaining_sum = sum;

    /*@
        loop invariant 0 <= remaining_sum <= total_sum(A, P);
        loop invariant 0 <= i <= (total_sum(A, P) - remaining_sum) / 2;
        loop invariant remaining_sum == total_sum(A, P) - 2 * i;
        loop assigns remaining_sum, i;
        loop variant remaining_sum;
    */
    while (remaining_sum >= 2)
    {
        //@ assert remaining_sum >= 2;
        remaining_sum -= 2;
        i += 1;
    }

    result = (int32_t)i;
    //@ assert result >= 0;
    return result;
}
