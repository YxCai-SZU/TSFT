#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(size_t N, long *B) =
    N >= 2 && N <= 100 &&
    \valid(B + (0 .. N-2)) &&
    \forall integer j; 0 <= j <= N-2 ==> 0 <= B[j] && B[j] <= 100000;
*/

/*@ logic integer ans_upper_bound(integer i) = 100000 * (i + 1); */

/*@ lemma ans_non_negative:
    \forall size_t N, long *B, integer i, integer ans;
    valid_params(N, B) && 0 <= i <= N-2 && ans >= 0 && ans <= ans_upper_bound(i) ==>
    ans >= 0;
*/

/*@ lemma ans_bound_preserved:
    \forall size_t N, long *B, integer i, integer ans, integer min_val;
    valid_params(N, B) && 0 <= i <= N-3 && ans >= 0 && ans <= ans_upper_bound(i) &&
    0 <= min_val && min_val <= 100000 ==>
    ans + min_val >= 0 && ans + min_val <= ans_upper_bound(i+1);
*/

/*@
requires valid_params(N, B);
ensures \result >= 0;
*/
long func(size_t N, const long *B)
{
    long ans;
    size_t i;
    long min_value;
    
    //@ assert valid_params(N, B);
    ans = B[0];
    i = 0;
    
    /*@ loop invariant 0 <= i <= N-2;
        loop invariant valid_params(N, B);
        loop invariant ans >= 0;
        loop invariant ans <= ans_upper_bound(i);
        loop assigns ans, i, min_value;
        loop variant N-2 - i;
    */
    while (i < N-2)
    {
        //@ assert 0 <= i <= N-3;
        //@ assert B[i] >= 0 && B[i] <= 100000;
        //@ assert B[i+1] >= 0 && B[i+1] <= 100000;
        
        if (B[i] < B[i+1])
            min_value = B[i];
        else
            min_value = B[i+1];
        
        //@ assert 0 <= min_value && min_value <= 100000;
        //@ assert ans + min_value >= 0;
        ans += min_value;
        i += 1;
    }
    
    //@ assert i == N-2;
    //@ assert B[N-2] >= 0 && B[N-2] <= 100000;
    //@ assert ans + B[N-2] >= 0;
    ans += B[N-2];
    return ans;
}
