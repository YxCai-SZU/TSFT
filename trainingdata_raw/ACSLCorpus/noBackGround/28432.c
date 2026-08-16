#include <limits.h>

/*@
    requires (0 <= (h1) && (h1) < 24 &&
        0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 &&
        0 <= (m2) && (m2) < 60);
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    requires 0 <= k && k < 1440;
    ensures \result == (60 * ((h2) - (h1)) + (m2) - (m1) - (k));
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int x;

    //@ assert (0 <= (h1) && (h1) < 24 &&         0 <= (m1) && (m1) < 60);
    //@ assert (0 <= (h2) && (h2) < 24 &&         0 <= (m2) && (m2) < 60);
    //@ assert ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    //@ assert 0 <= k && k < 1440;

    x = 60 * (h2 - h1) + m2 - m1 - k;

    //@ assert x == (60 * ((h2) - (h1)) + (m2) - (m1) - (k));
    return x;
}
