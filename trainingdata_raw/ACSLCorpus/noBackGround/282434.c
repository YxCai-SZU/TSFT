#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    ensures \result == (c - b == b - a);
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a <= 10;
    //@ assert 1 <= b <= 10;
    //@ assert 1 <= c <= 10;

    // Critical verification property for arithmetic safety
    //@ assert c - b >= -2147483648 && c - b <= 2147483647;

    result = (c - b == b - a);
    return result;
}
