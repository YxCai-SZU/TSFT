#include <stdbool.h>

/*@
    requires 0 <= a <= 123;
    requires 0 <= b <= 123;
    requires 0 <= c <= 123;
    requires 0 <= d <= 123;
    requires 0 <= e <= 123;
    requires 0 <= k <= 123;
    requires ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    ensures \result == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
*/
bool func(int a, int b, int c, int d, int e, int k)
{
    bool is_covered = false;

    //@ assert ((a) < (b) && (b) < (c) && (c) < (d) && (d) < (e));
    //@ assert 0 <= ((b) - (a));
    //@ assert 0 <= ((c) - (a));
    //@ assert 0 <= ((d) - (a));
    //@ assert 0 <= ((e) - (a));

    if (b - a <= k)
    {
        is_covered = true;
    }
    else if (c - a <= k)
    {
        is_covered = true;
    }
    else if (d - a <= k)
    {
        is_covered = true;
    }
    else if (e - a <= k)
    {
        is_covered = true;
    }

    //@ assert is_covered == (b - a <= k || c - a <= k || d - a <= k || e - a <= k);
    return is_covered;
}
