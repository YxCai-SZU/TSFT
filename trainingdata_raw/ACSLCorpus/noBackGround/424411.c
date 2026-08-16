#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= 100);
    ensures \result == ((n) * (m) - ((n) - 1 + (m) - 1));
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int result;
    int subtract = 0;

    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;

    // Overflow safety
    //@ assert 1 <= n * m && n * m <= 10000;

    result = n * m;

    if (n > 1)
    {
        subtract += n - 1;
    }

    if (m > 1)
    {
        subtract += m - 1;
    }

    // Bounds verification
    //@ assert 0 <= subtract && subtract <= 198;

    // Final computation
    return result - subtract;
}
