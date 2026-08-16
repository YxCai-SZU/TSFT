#include <limits.h>

/*@
    predicate is_nonnegative(integer v) = v >= 0;
    predicate within_bounds(integer v, integer n, integer m) = v <= n + m;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result <= n + m;
*/
int func(int n, int m)
{
    int x;
    int y;
    int z;

    //@ assert is_nonnegative(n);
    //@ assert is_nonnegative(m);
    //@ assert is_nonnegative(n + m - 1);

    if (n > m) {
        x = n - m;
    } else {
        x = m - n;
    }
    //@ assert is_nonnegative(x);
    //@ assert within_bounds(x, n, m);

    if (n + m - 1 >= x) {
        y = n + m - 1;
    } else {
        y = x;
    }
    //@ assert is_nonnegative(y);
    //@ assert within_bounds(y, n, m);

    if (y >= 0) {
        z = y;
    } else {
        z = 0;
    }
    //@ assert is_nonnegative(z);
    //@ assert within_bounds(z, n, m);

    return z;
}
