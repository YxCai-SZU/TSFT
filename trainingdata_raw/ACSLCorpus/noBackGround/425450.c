#include <stdbool.h>

/*@
    requires (0 <= (h1) && (h1) < 24 && 0 <= (m1) && (m1) < 60);
    requires (0 <= (h2) && (h2) < 24 && 0 <= (m2) && (m2) < 60);
    requires k >= 0;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    requires (((h2) - (h1)) * 60 + (m2) - (m1)) >= k;
    ensures \result >= 0;
    ensures \result == (((h2) - (h1)) * 60 + (m2) - (m1)) - k;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int result;
    //@ assert (((h2) - (h1)) * 60 + (m2) - (m1)) >= k;
    result = (h2 - h1) * 60 + m2 - m1 - k;
    return result;
}
