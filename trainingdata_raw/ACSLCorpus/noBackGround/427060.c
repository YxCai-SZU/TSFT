#include <limits.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);

    if (n > m + 1)
    {
        result = 1;
    }
    else if (n == m + 1)
    {
        result = 0;
    }
    else
    {
        result = m - n + 1;
    }

    //@ assert result >= 0;
    //@ assert result <= n + m;

    return result;
}
