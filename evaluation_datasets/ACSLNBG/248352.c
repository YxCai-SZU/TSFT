#include <limits.h>


int func(int h1, int m1, int h2, int m2, int k)
{
    int s;
    int t;
    int ans;
    int result;

    //@ assert (0 <= (h1) && (h1) < 24 &&         0 <= (m1) && (m1) < 60);
    //@ assert (0 <= (h2) && (h2) < 24 &&         0 <= (m2) && (m2) < 60);
    //@ assert h1 <= h2;
    //@ assert (h1 == h2) ==> (m1 <= m2);
    //@ assert k >= 0;

    s = h1 * 60 + m1;
    t = h2 * 60 + m2;
    ans = t - s - k;

    //@ assert s == h1 * 60 + m1;
    //@ assert t == h2 * 60 + m2;
    //@ assert ans == t - s - k;

    if (ans < 0)
    {
        //@ assert ans < 0;
        result = 0;
    }
    else
    {
        //@ assert ans >= 0;
        //@ assert ans <= (h2 - h1) * 60 + (m2 - m1);
        //@ assert ans == (h2 - h1) * 60 + (m2 - m1) - k || ans == 0;
        result = ans;
    }

    //@ assert result >= 0;
    //@ assert result <= (h2 - h1) * 60 + (m2 - m1);
    //@ assert result == (h2 - h1) * 60 + (m2 - m1) - k || result == 0;
    return result;
}
