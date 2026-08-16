#include <stdbool.h>
/*@
    requires (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ensures 1 <= \result <= N;
    ensures \result == ((N) + 1 - (i));
    assigns \nothing;
*/
int func(int N, int i) {
    int ans;
    //@ assert (1 <= (N) <= 100 && 1 <= (i) <= (N));
    ans = N + 1 - i;
    //@ assert ans == ((N) + 1 - (i));
    //@ assert 1 <= ans <= N;
    return ans;
}
