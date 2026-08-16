#include <limits.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires 0 <= k;
    requires ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    ensures \result == ((h2) * 60 + (m2)) - ((h1) * 60 + (m1)) - k;
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    //@ assert ((h1) * 60 + (m1)) <= ((h2) * 60 + (m2));
    return h2 * 60 + m2 - h1 * 60 - m1 - k;
}
