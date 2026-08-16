#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 10 &&
        0 <= (k) && (k) <= (n) * (n));
    ensures \result == ((n) * (n) - (k));
    assigns \nothing;
*/
int func(int n, int k)
{
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= n && n <= 10;
    //@ assert 0 <= k && k <= n * n;
    
    //@ assert n * n <= 100;
    //@ assert n * n - k >= 0;

    result = n * n - k;
    
    //@ assert result == ((n) * (n) - (k));
    return result;
}
