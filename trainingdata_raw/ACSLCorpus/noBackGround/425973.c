#include <limits.h>

/*@
    requires (1 <= (n) <= 100 &&
        0 <= (a) <= (n) * (n));
    ensures \result == n * n - a;
    assigns \nothing;
*/
int func(int n, int a)
{
    // Variable declarations at scope top
    int max_val;
    int diff;
    int result;

    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;

    // Manual max implementation
    if (n * n > a) {
        max_val = n * n;
    } else {
        max_val = a;
    }

    // Manual abs implementation
    if (max_val - a < 0) {
        diff = -(max_val - a);
    } else {
        diff = max_val - a;
    }

    // Ensure diff is non-negative
    //@ assert diff >= 0;

    // Overflow safety checks
    //@ assert n * n >= 0;
    //@ assert n * n <= 10000;
    //@ assert a >= 0;
    //@ assert a <= 10000;
    //@ assert n * n >= a;
    //@ assert n * n - a >= 0;

    result = n * n - a;
    //@ assert result == n * n - a;
    return result;
}
