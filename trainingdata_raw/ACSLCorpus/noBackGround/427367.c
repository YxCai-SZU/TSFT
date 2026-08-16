#include <stdbool.h>

/*@
    requires (0 <= (h1) <= 23 && 0 <= (m1) <= 59);
    requires (0 <= (h2) <= 23 && 0 <= (m2) <= 59);
    requires 0 <= k <= 100000;
    requires ((h1) < (h2) || ((h1) == (h2) && (m1) <= (m2)));
    ensures \result == (((h2) - (h1)) * 60 + (m2) - (m1) - (k));
    assigns \nothing;
*/
int func(int h1, int m1, int h2, int m2, int k)
{
    int result;
    int hour_diff;
    int temp;

    //@ assert 0 <= h2 - h1 <= 23;
    hour_diff = h2 - h1;

    //@ assert 0 <= hour_diff * 60 <= 23 * 60;
    temp = hour_diff * 60 + m2 - m1 - k;

    //@ assert temp == (((h2) - (h1)) * 60 + (m2) - (m1) - (k));
    result = temp;
    return result;
}
