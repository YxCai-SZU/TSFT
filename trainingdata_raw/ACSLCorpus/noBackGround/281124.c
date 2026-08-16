#include <stdbool.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == (b < c || d < a);
*/
bool func(long a, long b, long c, long d)
{
    long l;
    long r;
    bool result;

    //@ assert (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    //@ assert ((a) <= (b)) && ((c) <= (d));

    if (a > c) {
        l = a;
    } else {
        l = c;
    }

    //@ assert ((l) == (a) || (l) == (c));

    if (b < d) {
        r = b;
    } else {
        r = d;
    }

    //@ assert ((r) == (b) || (r) == (d));

    result = (r < l);

    //@ assert ((result) == ((b) < (c) || (d) < (a)));
    return result;
}
