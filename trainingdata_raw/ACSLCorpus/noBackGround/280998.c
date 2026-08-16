#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 9 &&
        1 <= (b) && (b) <= 9 &&
        1 <= (c) && (c) <= 9);
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((a) != (b) && (b) == (c)) ||
        ((a) == (c) && (a) != (b)));
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    bool ans = false;

    //@ assert (1 <= (a) && (a) <= 9 &&         1 <= (b) && (b) <= 9 &&         1 <= (c) && (c) <= 9);

    if ((a == b && a != c) || (a != b && b == c) || (a == c && a != b))
    {
        ans = true;
    }

    //@ assert ans == 1 <==> (((a) == (b) && (a) != (c)) ||         ((a) != (b) && (b) == (c)) ||         ((a) == (c) && (a) != (b)));

    return ans;
}
