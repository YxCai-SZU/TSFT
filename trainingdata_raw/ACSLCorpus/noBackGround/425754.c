#include <limits.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures (n <= 9 && m <= 9 ==> \result == n * m) &&
            (!(n <= 9 && m <= 9) ==> \result == -1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int max_val;
    int min_val;
    int ans;

    max_val = (n > m) ? n : m;
    min_val = (n < m) ? n : m;

    //@ assert max_val >= min_val;

    if (max_val <= 9)
    {
        //@ assert 1 <= n <= 9 && 1 <= m <= 9;
        //@ assert 1 <= n * m <= 81;
        ans = n * m;
    }
    else
    {
        ans = -1;
    }

    return ans;
}
