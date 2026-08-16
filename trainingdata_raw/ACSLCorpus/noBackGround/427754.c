#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures \result == ((1 <= (n) <= 9 && 1 <= (m) <= 9) ? (n) * (m) : -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int result = 0;

    //@ assert (1 <= (n) <= 20) && (1 <= (m) <= 20);

    if (1 <= n && n <= 9)
    {
        if (1 <= m && m <= 9)
        {
            //@ assert 1 <= n * m <= 81;
            result = n * m;
        }
        else
        {
            result = -1;
        }
    }
    else
    {
        result = -1;
    }

    //@ assert result == ((1 <= (n) <= 9 && 1 <= (m) <= 9) ? (n) * (m) : -1);
    return result;
}
