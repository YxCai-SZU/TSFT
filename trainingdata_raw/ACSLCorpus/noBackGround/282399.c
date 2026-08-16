#include <limits.h>

/*@
    requires (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59) && (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    requires 0 <= k && k <= 100000;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == (h2 - h1) * 60 + m2 - m1 - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int start_minutes;
    int end_minutes;
    int ans;

    //@ assert (0 <= (h1) && (h1) <= 23 && 0 <= (m1) && (m1) <= 59);
    //@ assert (0 <= (h2) && (h2) <= 23 && 0 <= (m2) && (m2) <= 59);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));

    start_minutes = h1 * 60 + m1;
    end_minutes = h2 * 60 + m2;
    ans = end_minutes - start_minutes - k;

    //@ assert start_minutes == ((h1) * 60 + (m1));
    //@ assert end_minutes == ((h2) * 60 + (m2));
    //@ assert ans == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    //@ assert ans == (h2 - h1) * 60 + m2 - m1 - k;

    return ans;
}
