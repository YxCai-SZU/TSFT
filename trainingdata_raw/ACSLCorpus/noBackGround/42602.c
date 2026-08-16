#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 10000 &&
        (b) >= 1 && (b) <= 10000 &&
        (c) >= 1 && (c) <= 10000 &&
        (d) >= 1 && (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_all;
    int ans;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    //@ assert min_ab == (((((a)) < ((b))) ? ((a)) : ((b))));
    //@ assert min_ab >= 1 && min_ab <= 10000;

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    //@ assert min_cd == (((((c)) < ((d))) ? ((c)) : ((d))));
    //@ assert min_cd >= 1 && min_cd <= 10000;

    if (min_ab < min_cd) {
        min_all = min_ab;
    } else {
        min_all = min_cd;
    }

    //@ assert min_all == (((((min_ab)) < ((min_cd))) ? ((min_ab)) : ((min_cd))));
    //@ assert min_all >= 1 && min_all <= 10000;
    //@ assert min_ab + min_cd <= 20000;

    if (d < min_ab + min_cd) {
        ans = min_ab + min_cd - d;
    } else {
        ans = min_ab + min_cd;
    }

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;

    return ans;
}
