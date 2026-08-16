#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires n == (int64_t)n;
    requires m == (int64_t)m;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
 */
int64_t func(int64_t n, int64_t m)
{
    int64_t max_val;
    int64_t result;

    max_val = (n > 2 * m) ? n : 2 * m;

    //@ assert ((max_val) == (n) || (max_val) == 2 * (m));

    if (max_val == n)
    {
        result = n - 2 * m;
    }
    else
    {
        result = 0;
    }

    return result;
}
