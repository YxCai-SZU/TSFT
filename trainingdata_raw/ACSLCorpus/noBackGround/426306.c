#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    requires (0 <= (m) && (m) <= (n) * (n));
    ensures \result == n * n - m;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert (0 <= (m) && (m) <= (n) * (n));
    //@ assert ((n) * (n) <= 10000);
    
    result = n * n - m;
    return result;
}
