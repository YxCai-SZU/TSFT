#include <limits.h>

/*@
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    requires -1000000000 <= d <= 1000000000;
    requires a <= b;
    requires c <= d;
    ensures \result == b*d || \result == b*c || \result == a*d || \result == a*c;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max_value;
    long long ac;
    long long ad;
    long long bc;
    long long bd;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert a <= b;
    //@ assert c <= d;

    ac = a * c;
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    ad = a * d;
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    bc = b * c;
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    bd = b * d;
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    max_value = ac;
    //@ assert max_value == ac;
    if (max_value < ad) {
        max_value = ad;
        //@ assert max_value == ad;
    }
    //@ assert max_value >= ac && max_value >= ad;
    if (max_value < bc) {
        max_value = bc;
        //@ assert max_value == bc;
    }
    //@ assert max_value >= ac && max_value >= ad && max_value >= bc;
    if (max_value < bd) {
        max_value = bd;
        //@ assert max_value == bd;
    }
    //@ assert max_value >= ac && max_value >= ad && max_value >= bc && max_value >= bd;

    //@ assert max_value == (((ac) >= (ad) && (ac) >= (bc) && (ac) >= (bd)) ? (ac) :         ((ad) >= (ac) && (ad) >= (bc) && (ad) >= (bd)) ? (ad) :         ((bc) >= (ac) && (bc) >= (ad) && (bc) >= (bd)) ? (bc) : (bd));
    //@ assert max_value == b*d || max_value == b*c || max_value == a*d || max_value == a*c;
    return max_value;
}
