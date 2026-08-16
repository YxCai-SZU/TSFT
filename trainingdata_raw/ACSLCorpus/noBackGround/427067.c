#include <limits.h>

/*@ requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60) && (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires ((h1) <= (h2) && ((h1) == (h2) ==> (m1) <= (m2)));
    requires k >= 0;
    ensures \result >= 0;
    ensures \result <= (h2 - h1) * 60 + m2 - m1;
    ensures \result == (h2 - h1) * 60 + m2 - m1 - k || \result == 0;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int ans;
    int result;

    t1 = 60 * h1 + m1;
    t2 = 60 * h2 + m2;
    ans = t2 - t1 - k;

    if (ans > 0)
    {
        //@ assert ans <= (h2 - h1) * 60 + m2 - m1;
        result = ans;
    }
    else
    {
        result = 0;
    }

    return result;
}
