#include <limits.h>

/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures \result >= 1 && \result <= N;
    ensures \result == N + 1 - i;
    assigns \nothing;
*/
int func(int N, int i) {
    int ans;
    
    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ans = N + 1 - i;
    
    //@ assert ans == N + 1 - i;
    //@ assert ans >= 1;
    //@ assert ans <= N;
    
    return ans;
}
