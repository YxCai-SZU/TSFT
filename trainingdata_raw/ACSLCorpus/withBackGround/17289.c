#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;

    logic integer product(integer x, integer y) = x * y;

    lemma product_bound:
        \forall integer x, y;
            valid_range(x) && valid_range(y) ==> product(x, y) <= 100000000;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(d);
    ensures \result >= 0;
    ensures \result == product(a, b) || \result == product(c, d) || 
            \result == product(a, c) || \result == product(a, d) || 
            \result == product(b, c) || \result == product(b, d);
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_val;
    int cd;
    int ac;
    int ad;
    int bc;
    int bd;

    //@ assert valid_range(a) && valid_range(b);
    //@ assert product(a, b) <= 100000000;
    max_val = a * b;

    //@ assert valid_range(c) && valid_range(d);
    //@ assert product(c, d) <= 100000000;
    cd = c * d;
    if (cd > max_val) {
        max_val = cd;
    }

    //@ assert valid_range(a) && valid_range(c);
    //@ assert product(a, c) <= 100000000;
    ac = a * c;
    if (ac > max_val) {
        max_val = ac;
    }

    //@ assert valid_range(a) && valid_range(d);
    //@ assert product(a, d) <= 100000000;
    ad = a * d;
    if (ad > max_val) {
        max_val = ad;
    }

    //@ assert valid_range(b) && valid_range(c);
    //@ assert product(b, c) <= 100000000;
    bc = b * c;
    if (bc > max_val) {
        max_val = bc;
    }

    //@ assert valid_range(b) && valid_range(d);
    //@ assert product(b, d) <= 100000000;
    bd = b * d;
    if (bd > max_val) {
        max_val = bd;
    }

    return max_val;
}
