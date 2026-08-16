#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == (a == b + c || b == c + a || c == a + b);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (a) && (a) <= 9);
    //@ assert (1 <= (b) && (b) <= 9);
    //@ assert (1 <= (c) && (c) <= 9);

    //@ assert 1 <= b + c && b + c <= 18;
    //@ assert 1 <= c + a && c + a <= 18;
    //@ assert 1 <= a + b && a + b <= 18;

    result = (a == b + c) || (b == c + a) || (c == a + b);
    return result;
}
