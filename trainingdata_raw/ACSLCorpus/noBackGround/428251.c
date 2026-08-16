#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int res;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    //@ assert max_ab == a || max_ab == b;

    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    //@ assert max_cd == c || max_cd == d;

    //@ assert (-100 <= (max_ab) <= 100);
    //@ assert (-100 <= (max_cd) <= 100);

    res = max_ab + max_cd;
    //@ assert -200 <= res <= 200;
    //@ assert res == a + c || res == a + d || res == b + c || res == b + d;

    return res;
}
