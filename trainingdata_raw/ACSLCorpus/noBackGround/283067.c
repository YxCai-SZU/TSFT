#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 1;
    ensures \result <= 3;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c)
{
    int64_t ab;
    int64_t bc;
    int64_t ca;

    if (a > b) {
        ab = a - b;
    } else {
        ab = b - a;
    }

    if (b > c) {
        bc = b - c;
    } else {
        bc = c - b;
    }

    if (c > a) {
        ca = c - a;
    } else {
        ca = a - c;
    }

    //@ assert ab >= 0;
    //@ assert bc >= 0;
    //@ assert ca >= 0;

    if ((ab + bc == ca) || (bc + ca == ab) || (ca + ab == bc)) {
        //@ assert ab + bc == ca || bc + ca == ab || ca + ab == bc;
        return 1;
    } else if ((ab + bc > ca) && (bc + ca > ab) && (ca + ab > bc)) {
        //@ assert ab + bc > ca && bc + ca > ab && ca + ab > bc;
        return 2;
    } else {
        //@ assert !(ab + bc == ca || bc + ca == ab || ca + ab == bc) && !(ab + bc > ca && bc + ca > ab && ca + ab > bc);
        return 3;
    }
}
