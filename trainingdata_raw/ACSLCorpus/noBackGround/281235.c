#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert -9 <= b - a <= 9;
    //@ assert -9 <= c - b <= 9;
    //@ assert -18 <= (b - a) * 2 <= 18;
    //@ assert -18 <= (c - b) * 2 <= 18;

    result = (b - a == c - b);
    return result;
}
