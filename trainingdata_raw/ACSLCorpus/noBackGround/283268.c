#include <limits.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires k >= 0;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result >= -k;
    ensures \result <= (60 * ((h2) - (h1)) + ((m2) - (m1)));
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int x;

    //@ assert 0 <= 60 * (h2 - h1) <= 60 * 23;
    //@ assert 0 <= 60 * (h2 - h1) + (m2 - m1) <= 60 * 23 + 59;

    x = -k + 60 * (h2 - h1) + (m2 - m1);

    //@ assert x >= -k;
    return x;
}
