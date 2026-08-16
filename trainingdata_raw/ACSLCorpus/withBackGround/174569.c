#include <stdint.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 20;
    
    predicate both_small(integer n, integer m) = n <= 9 && m <= 9;
    
    predicate overflow_safe(integer n, integer m) = n * m <= 81;
*/

/*@
    requires valid_range(N) && valid_range(M);
    ensures (N > 9 || M > 9) ==> \result == -1;
    ensures both_small(N, M) ==> \result == N * M;
    assigns \nothing;
*/
int32_t func(uint32_t N, uint32_t M)
{
    // Variable declarations at scope top
    int32_t res;
    
    if (N > 9 || M > 9) {
        //@ assert N > 9 || M > 9;
        return -1;
    }
    
    //@ assert both_small(N, M);
    //@ assert overflow_safe(N, M);
    
    res = (int32_t)(N * M);
    return res;
}
