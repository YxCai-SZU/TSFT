#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000) && (-1000 <= (c) <= 1000) && (-1000 <= (d) <= 1000);
    ensures \result == a * b || \result == a * c || \result == a * d ||
            \result == b * c || \result == b * d || \result == c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int ab;
    int ac;
    int ad;
    int bc;
    int bd;
    int cd;
    int max_val;

    // Precondition lemmas for product bounds
    //@ assert (-1000000 <= (a) * (b) <= 1000000);
    //@ assert (-1000000 <= (a) * (c) <= 1000000);
    //@ assert (-1000000 <= (a) * (d) <= 1000000);
    //@ assert (-1000000 <= (b) * (c) <= 1000000);
    //@ assert (-1000000 <= (b) * (d) <= 1000000);
    //@ assert (-1000000 <= (c) * (d) <= 1000000);

    ab = a * b;
    ac = a * c;
    ad = a * d;
    bc = b * c;
    bd = b * d;
    cd = c * d;

    max_val = ab;
    //@ assert max_val == a * b;

    if (ac > max_val) {
        max_val = ac;
    }
    //@ assert max_val == a * b || max_val == a * c;

    if (ad > max_val) {
        max_val = ad;
    }
    //@ assert max_val == a * b || max_val == a * c || max_val == a * d;

    if (bc > max_val) {
        max_val = bc;
    }
    //@ assert max_val == a * b || max_val == a * c || max_val == a * d || max_val == b * c;

    if (bd > max_val) {
        max_val = bd;
    }
    //@ assert max_val == a * b || max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;

    if (cd > max_val) {
        max_val = cd;
    }
    //@ assert max_val == a * b || max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d || max_val == c * d;

    return max_val;
}
