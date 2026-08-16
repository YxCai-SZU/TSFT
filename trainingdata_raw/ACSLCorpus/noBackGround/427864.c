#include <limits.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59) && (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    requires k >= 0;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int ans;

    //@ assert (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    //@ assert (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    //@ assert k >= 0;

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;

    //@ assert t1 == (60 * (h1) + (m1));
    //@ assert t2 == (60 * (h2) + (m2));

    if (t1 < t2)
    {
        ans = t2 - t1;
    }
    else
    {
        ans = t2 - t1 + 24 * 60;
    }

    //@ assert ans == ((t1) < (t2) ? (t2) - (t1) : (t2) - (t1) + 24 * 60);
    //@ assert ans >= 0;

    ans = ans - k;

    if (ans < 0)
    {
        //@ assert 0 >= 0;
        return 0;
    }
    else
    {
        //@ assert ans >= 0;
        return ans;
    }
}
