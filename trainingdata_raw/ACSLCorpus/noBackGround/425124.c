#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result <==> (((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)));
*/
bool func(int a, int b, int c)
{
    bool x;
    bool y;
    bool z;
    bool result;

    x = (a == b);
    y = (b == c);
    z = (c == a);

    //@ assert x <==> (a == b);
    result = (x && !y) || (y && !z) || (z && !x);
    return result;
}
