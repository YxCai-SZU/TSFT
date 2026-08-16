#include <stdbool.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        1 <= (a) && (a) < (b) && (b) <= (n));
    ensures \result == ((a + b) % 2 == 0);
*/
bool func(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int f;
    unsigned int g;
    unsigned int h;

    //@ assert 1 <= a && a < b && b <= n;

    if (a + 1 < b) {
        c = a + 1;
    } else {
        c = b + 1;
    }

    if (b - 1 > a) {
        d = b - 1;
    } else {
        d = a - 1;
    }

    if ((a + b) % 2 == 0) {
        e = (a + b) / 2;
    } else {
        e = (a + b) / 2 + 1;
    }

    //@ assert e == (((a) + (b)) % 2 == 0 ? ((a) + (b)) / 2 : ((a) + (b)) / 2 + 1);

    if (e <= c || e <= d) {
        f = e;
    } else {
        f = c;
    }

    if (c > d) {
        g = c;
    } else {
        g = d;
    }

    if (e <= g) {
        h = e;
    } else {
        h = g;
    }

    //@ assert h == (a + b) / 2 || h == (a + b) / 2 + 1;

    return (a + b) % 2 == 0;
}
