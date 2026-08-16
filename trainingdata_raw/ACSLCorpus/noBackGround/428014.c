#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    requires (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max1;
    int max2;
    int res;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }
    //@ assert max1 == a || max1 == b;
    //@ assert (1 <= (max1) <= 100);

    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }
    //@ assert max2 == c || max2 == d;
    //@ assert (1 <= (max2) <= 100);

    res = max1 + max2;
    //@ assert res == max1 + max2;
    //@ assert 2 <= res <= 200;

    return res;
}
