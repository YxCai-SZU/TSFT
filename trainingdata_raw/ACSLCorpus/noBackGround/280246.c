#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result == (b - a == c - b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert -99 <= b - a <= 99;
    //@ assert -99 <= c - b <= 99;
    //@ assert -198 <= (b - a) - (c - b) <= 198;

    result = (b - a == c - b);
    return result;
}
