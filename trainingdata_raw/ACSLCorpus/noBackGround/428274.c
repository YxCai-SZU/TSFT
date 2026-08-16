#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100 && 1 <= (i) && (i) <= (N));
    ensures \result == ((N) - ((i) - 1));
    assigns \nothing;
*/
int func(int N, int i)
{
    int ans;
    //@ assert (1 <= (N) && (N) <= 100 && 1 <= (i) && (i) <= (N));
    ans = N - (i - 1);
    //@ assert ans == ((N) - ((i) - 1));
    return ans;
}
