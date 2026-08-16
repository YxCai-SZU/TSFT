#include <stdbool.h>

/*@
    requires (0 <= (a) <= 123 &&
        0 <= (b) <= 123 &&
        0 <= (c) <= 123 &&
        0 <= (d) <= 123 &&
        0 <= (e) <= 123 &&
        (a) < (b) &&
        (b) < (c) &&
        (c) < (d) &&
        (d) < (e));
    requires 0 <= k <= 123;
    ensures \result == (k <= (e - a) || k <= (b - a) || k <= (c - a) || k <= (d - a));
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    int count = 0;

    //@ assert (0 <= (a) <= 123 &&         0 <= (b) <= 123 &&         0 <= (c) <= 123 &&         0 <= (d) <= 123 &&         0 <= (e) <= 123 &&         (a) < (b) &&         (b) < (c) &&         (c) < (d) &&         (d) < (e));
    //@ assert 0 <= k <= 123;

    if (k <= (e - a))
    {
        count += 1;
    }
    if (k <= (b - a))
    {
        count += 1;
    }
    if (k <= (c - a))
    {
        count += 1;
    }
    if (k <= (d - a))
    {
        count += 1;
    }

    //@ assert count >= 1 ==> (k <= (e - a) || k <= (b - a) || k <= (c - a) || k <= (d - a));

    return count >= 1;
}
