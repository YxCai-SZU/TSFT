#include <limits.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    ensures \result == a + b || \result == b + c || \result == c + d || \result == a + d;
    ensures \result >= a + b;
    ensures \result >= b + c;
    ensures \result >= c + d;
    ensures \result >= a + d;
*/
int func(int a, int b, int c, int d)
{
    int ab;
    int bc;
    int cd;
    int ad;
    int max1;
    int max2;
    int res;

    ab = a + b;
    bc = b + c;
    cd = c + d;
    ad = a + d;

    //@ assert (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    //@ assert ab == a + b && bc == b + c && cd == c + d && ad == a + d;

    if (ab > bc) {
        max1 = ab;
    } else {
        max1 = bc;
    }
    //@ assert max1 == (((ab) > (bc)) ? (ab) : (bc));
    //@ assert max1 >= ab && max1 >= bc;

    if (cd > ad) {
        max2 = cd;
    } else {
        max2 = ad;
    }
    //@ assert max2 == (((cd) > (ad)) ? (cd) : (ad));
    //@ assert max2 >= cd && max2 >= ad;

    if (max1 > max2) {
        res = max1;
    } else {
        res = max2;
    }
    //@ assert res == (((max1) > (max2)) ? (max1) : (max2));
    //@ assert res >= max1 && res >= max2;

    //@ assert res >= a + b;
    //@ assert res >= b + c;
    //@ assert res >= c + d;
    //@ assert res >= a + d;
    //@ assert res == a + b || res == b + c || res == c + d || res == a + d;

    return res;
}
