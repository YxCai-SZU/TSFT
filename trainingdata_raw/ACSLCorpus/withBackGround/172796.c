#include <stdint.h>

/*@
    predicate is_valid_input(integer N, integer M) =
        1 <= N <= 20 && 1 <= M <= 20;
    
    predicate both_small(integer N, integer M) =
        N <= 9 && M <= 9;
    
    predicate at_least_one_large(integer N, integer M) =
        N > 9 || M > 9;
*/

/*@
    requires is_valid_input(N, M);
    ensures both_small(N, M) ==> \result == N * M;
    ensures at_least_one_large(N, M) ==> \result == -1;
*/
int64_t func(int64_t N, int64_t M) {
    int64_t result;
    int N_is_less_or_equal_9;
    int M_is_less_or_equal_9;
    
    N_is_less_or_equal_9 = (N <= 9);
    M_is_less_or_equal_9 = (M <= 9);
    
    if (N_is_less_or_equal_9 && M_is_less_or_equal_9) {
        //@ assert 1 <= N <= 9;
        //@ assert 1 <= M <= 9;
        //@ assert 1 <= N * M <= 81;
        result = N * M;
    } else {
        result = -1;
    }
    
    return result;
}
