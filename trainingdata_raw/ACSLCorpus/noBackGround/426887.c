#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((a) == (c) && (a) != (b)) ||
        ((b) == (c) && (a) != (b)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool x;
    bool y;
    bool result;

    //@ assert 1 <= a && a <= 9;
    //@ assert 1 <= b && b <= 9;
    //@ assert 1 <= c && c <= 9;

    x = (a == b) || (a == c) || (b == c);
    y = (a == b) && (a == c) && (b == c);
    result = x && !y;

    //@ assert result == 1 <==> (((a) == (b) && (a) != (c)) ||         ((a) == (c) && (a) != (b)) ||         ((b) == (c) && (a) != (b)));
    return result;
}
