#include <limits.h>

/*@
    requires (1 <= (n) <= 100 &&
        0 <= (a) <= (n) * (n));
    ensures \result == ((n) * (n) - (a));
    assigns \nothing;
*/
int func(int n, int a) {
    // Variable declarations at top of scope
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 100 * 100;
    //@ assert n * n >= a;

    result = n * n - a;
    return result;
}
