#include <stdint.h>

/*@ predicate valid_params(integer A, integer P) =
      0 <= A && A <= 100 &&
      0 <= P && P <= 100;
*/

/*@ logic integer compute_sum(integer A, integer P) =
      A * 3 + P;
*/

/*@ lemma sum_bounds:
      \forall integer A, integer P;
      valid_params(A, P) ==> 0 <= compute_sum(A, P) && compute_sum(A, P) <= 400;
*/

/*@
    requires valid_params(A, P);
    ensures \result >= 0;
    ensures \result == (A * 3 + P) / 2;
*/
int64_t func(int64_t A, int64_t P)
{
    int64_t sum;
    int64_t ans;
    int64_t count;

    sum = A * 3 + P;
    ans = 0;
    count = sum;

    /*@
        loop invariant 0 <= count <= sum;
        loop invariant ans >= 0;
        loop invariant sum == A * 3 + P;
        loop invariant ans * 2 == sum - count;
        loop assigns ans, count;
    */
    while (count >= 2)
    {
        //@ assert count >= 2;
        ans = ans + 1;
        count = count - 2;
        //@ assert ans * 2 == sum - count;
    }

    //@ assert ans * 2 <= sum && sum < ans * 2 + 2;
    return ans;
}
