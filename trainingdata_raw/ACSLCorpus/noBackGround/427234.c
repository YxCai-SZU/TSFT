#include <limits.h>

/*@
    requires ((h1) >= 0 && (m1) >= 0 &&
        (h1) < 24 && (m1) < 60) && ((h2) >= 0 && (m2) >= 0 &&
        (h2) < 24 && (m2) < 60);
    requires ((h1) <= (h2) && (m1) <= (m2));
    requires k >= 0;
    ensures \result >= 0;
    ensures \result <= (h2 - h1) * 60 + (m2 - m1);
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_minutes;
    int end_minutes;
    int ans;

    //@ assert h1 * 60 <= 24 * 60;
    //@ assert m1 <= 60;
    //@ assert h2 * 60 <= 24 * 60;
    //@ assert m2 <= 60;

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;

    if (end_minutes - start_minutes - k > 0)
    {
        ans = end_minutes - start_minutes - k;
    }
    else
    {
        ans = 0;
    }

    return ans;
}
