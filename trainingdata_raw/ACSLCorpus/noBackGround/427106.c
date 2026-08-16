#include <limits.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 23 * 60;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == (((h2) - (h1)) * 60 + (m2) - (m1) - (k));
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int ans;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));

    if (m1 > m2)
    {
        ans = (h2 - h1 - 1) * 60 + 60 + m2 - m1 - k;
        //@ assert ans == (h2 - h1 - 1) * 60 + 60 + m2 - m1 - k;
    }
    else
    {
        ans = (h2 - h1) * 60 + m2 - m1 - k;
        //@ assert ans == (h2 - h1) * 60 + m2 - m1 - k;
    }

    //@ assert ans == (((h2) - (h1)) * 60 + (m2) - (m1) - (k));
    return ans;
}
