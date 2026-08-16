#include <stdbool.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires 0 <= k && k < 24 * 60;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == (h2 - h1) * 60 + (m2 - m1) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int t1;
    int t2;
    int result;

    t1 = h1 * 60 + m1;
    t2 = h2 * 60 + m2;

    //@ assert t1 == ((h1) * 60 + (m1));
    //@ assert t2 == ((h2) * 60 + (m2));

    result = t2 - t1 - k;
    return result;
}
