#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 20);
    requires (1 <= (m) && (m) <= 20);
    ensures \result == ((n) < 10 ? (n) + (m) : (n) * 2 + (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;
    //@ assert (1 <= (n) && (n) <= 20) && (1 <= (m) && (m) <= 20);
    if (n < 10)
    {
        ans = n + m;
    }
    else
    {
        ans = n * 2 + m;
    }
    //@ assert ans == ((n) < 10 ? (n) + (m) : (n) * 2 + (m));
    return ans;
}
