#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int res;
    int abs_val;

    //@ assert (-1000000 <= (a) * (c) <= 1000000);
    res = a * c;

    //@ assert (-1000000 <= (a) * (d) <= 1000000);
    abs_val = a * d;
    if (abs_val > res) {
        res = abs_val;
    }

    //@ assert (-1000000 <= (b) * (d) <= 1000000);
    abs_val = b * d;
    if (abs_val > res) {
        res = abs_val;
    }

    //@ assert (-1000000 <= (b) * (c) <= 1000000);
    abs_val = b * c;
    if (abs_val > res) {
        res = abs_val;
    }

    //@ assert res == a * c || res == a * d || res == b * c || res == b * d;
    return res;
}
