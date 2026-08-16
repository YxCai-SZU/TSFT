#include <limits.h>

/*@
    requires ((n) * (n) * (n) >= INT_MIN && (n) * (n) * (n) <= INT_MAX);
    ensures \result == n * n * n;
    assigns \nothing;
*/
int func(int n)
{
    //@ assert n * n >= INT_MIN && n * n <= INT_MAX;
    int ans = n * n * n;
    //@ assert ans == n * n * n;
    return ans;
}
