#include <stdint.h>

/*@
    requires (1 <= (N) <= 100 && 0 <= (M) <= (N) * (N));
    ensures \result == ((N) * (N) - (M));
    assigns \nothing;
*/
int64_t func(int64_t N, int64_t M)
{
    // Variable declarations at scope top
    int64_t result;
    
    //@ assert 1 <= N && N <= 100;
    //@ assert 0 <= M && M <= N * N;
    //@ assert N * N <= 100 * 100;
    
    result = N * N - M;
    //@ assert result == ((N) * (N) - (M));
    
    return result;
}
