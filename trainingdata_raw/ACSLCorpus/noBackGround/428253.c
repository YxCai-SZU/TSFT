#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) + (b) + (c) + (d)) || \result == ((b) + (c));
*/
int func(int a, int b, int c, int d)
{
    int res;
    int x;
    int y;
    int s;

    x = a + b;
    y = c + d;
    s = x + y;

    //@ assert s == ((a) + (b) + (c) + (d));
    //@ assert ((b) + (c)) == b + c;

    if (s <= 0)
    {
        res = 0;
    }
    else if (s <= b + c)
    {
        res = b + c;
    }
    else
    {
        res = s;
    }

    //@ assert res == ((a) + (b) + (c) + (d)) || res == ((b) + (c));
    return res;
}
