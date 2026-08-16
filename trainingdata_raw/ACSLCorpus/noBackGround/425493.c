#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int max_val;
    int abs_val;
    int result;

    // Precondition assertions
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert n * n <= 10000;

    // Compute max_val
    if (n * n > m) {
        max_val = n * n;
    } else {
        max_val = m;
    }

    // Compute abs_val
    if (max_val - m < 0) {
        abs_val = -(max_val - m);
    } else {
        abs_val = max_val - m;
    }

    result = abs_val;

    // Postcondition verification
    //@ assert result == n * n - m;
    return result;
}
