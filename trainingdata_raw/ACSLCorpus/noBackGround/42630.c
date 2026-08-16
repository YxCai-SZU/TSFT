#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((((a * c) > (b * d) ? (a * c) : (b * d))) > (((a * d) > (b * c) ? (a * d) : (b * c))) ? (((a * c) > (b * d) ? (a * c) : (b * d))) : (((a * d) > (b * c) ? (a * d) : (b * c))));
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t x;
    int64_t y;
    int64_t ans;
    int64_t ac, bd, ad, bc;

    ac = a * c;
    bd = b * d;
    ad = a * d;
    bc = b * c;

    //@ assert 1 <= ac <= 10000;
    //@ assert 1 <= bd <= 10000;
    //@ assert 1 <= ad <= 10000;
    //@ assert 1 <= bc <= 10000;

    if (ac > bd) {
        x = ac;
    } else {
        x = bd;
    }

    //@ assert x == ((ac) > (bd) ? (ac) : (bd));

    if (ad > bc) {
        y = ad;
    } else {
        y = bc;
    }

    //@ assert y == ((ad) > (bc) ? (ad) : (bc));

    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }

    //@ assert ans == ((x) > (y) ? (x) : (y));
    return ans;
}
