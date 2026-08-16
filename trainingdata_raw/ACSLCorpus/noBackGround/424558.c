#include <limits.h>

/*@
    requires (2 <= (N) <= 100) && (2 <= (M) <= 100);
    ensures \result == (N - 1) * (M - 1);
    assigns \nothing;
*/
long func(long N, long M) {
    long result;
    
    //@ assert 1 <= N - 1 <= 99;
    //@ assert 1 <= M - 1 <= 99;
    //@ assert (N - 1) * (M - 1) <= 99 * 99;
    //@ assert (N - 1) * (M - 1) >= 1;
    
    result = (N - 1) * (M - 1);
    return result;
}
