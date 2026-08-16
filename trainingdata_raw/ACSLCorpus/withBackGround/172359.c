#include <stdint.h>

/*@
    predicate bounds(integer N, integer W) =
        N >= 1 && N <= 100 && W >= 1 && W <= 100;
    
    lemma product_bounds:
        \forall integer N, W; bounds(N, W) ==> N * W >= 1 && N * W <= 10000;
*/

/*@
    requires bounds(N, W);
    ensures \result == N * W;
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t W)
{
    //@ assert bounds(N, W);
    //@ assert N * W >= 1;
    //@ assert N * W <= 10000;
    
    int64_t ans;
    ans = N * W;
    
    //@ assert ans == N * W;
    return ans;
}
