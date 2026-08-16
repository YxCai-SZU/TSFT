#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result == ((b / d) >= (a / c));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    unsigned int x;
    unsigned int y;
    bool res;

    //@ assert valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    x = b / d;
    y = a / c;
    //@ assert x == b / d;
    //@ assert y == a / c;
    res = (x >= y);
    return res;
}
