#include <stdint.h>

/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A && A <= 100 &&
        0 <= P && P <= 100;

    logic integer total_sum(integer A, integer P) = A * 3 + P;

    lemma sum_bounds: \forall integer A, P; valid_inputs(A, P) ==> 0 <= total_sum(A, P) && total_sum(A, P) <= 400;
*/

/*@
    requires valid_inputs(A, P);
    ensures \result >= 0;
    ensures \result <= total_sum(A, P);
    assigns \nothing;
*/
int64_t func(int64_t A, int64_t P)
{
    // Variable declarations at scope top
    int64_t sum;
    int64_t result;
    int64_t count;

    //@ assert 0 <= A && A <= 100;
    //@ assert 0 <= P && P <= 100;
    
    //@ assert A * 3 <= 300;
    sum = A * 3 + P;
    result = 0;
    count = sum;

    /*@
        loop invariant 0 <= count && count <= sum;
        loop invariant result >= 0;
        loop invariant result <= sum - count;
        loop invariant sum == total_sum(A, P);
        loop invariant valid_inputs(A, P);
        loop assigns result, count;
        loop variant count;
    */
    while (count >= 2)
    {
        result += 1;
        count -= 2;
    }

    //@ assert result <= total_sum(A, P);
    return result;
}
