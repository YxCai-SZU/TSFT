#include <stdbool.h>

/*@
    requires (0 <= (a) < 124 &&
        0 <= (b) < 124 &&
        0 <= (c) < 124 &&
        0 <= (d) < 124 &&
        0 <= (e) < 124 &&
        0 <= (k) <= 123 &&
        (a) < (b) &&
        (b) < (c) &&
        (c) < (d) &&
        (d) < (e));
    ensures \result == (k <= e - a || k >= 0);
    assigns \nothing;
*/
bool func(long long a, long long b, long long c, long long d, long long e, long long k) {
    long long k_mut;
    long long a_mut;
    long long b_mut;
    long long c_mut;
    long long d_mut;
    long long e_mut;
    long long dist;

    k_mut = k;
    a_mut = a;
    b_mut = b;
    c_mut = c;
    d_mut = d;
    e_mut = e;

    //@ assert k_mut == k && a_mut == a && b_mut == b && c_mut == c && d_mut == d && e_mut == e;

    if (k_mut < 0) {
        k_mut = -k_mut;
    }
    //@ assert k_mut == (((k) < 0) ? -(k) : (k));

    if (a_mut < 0) {
        a_mut = -a_mut;
    }
    //@ assert a_mut == (((a) < 0) ? -(a) : (a));

    if (b_mut < 0) {
        b_mut = -b_mut;
    }
    //@ assert b_mut == (((b) < 0) ? -(b) : (b));

    if (c_mut < 0) {
        c_mut = -c_mut;
    }
    //@ assert c_mut == (((c) < 0) ? -(c) : (c));

    if (d_mut < 0) {
        d_mut = -d_mut;
    }
    //@ assert d_mut == (((d) < 0) ? -(d) : (d));

    if (e_mut < 0) {
        e_mut = -e_mut;
    }
    //@ assert e_mut == (((e) < 0) ? -(e) : (e));

    dist = e_mut - a_mut;
    //@ assert dist == (((e) < 0) ? -(e) : (e)) - (((a) < 0) ? -(a) : (a));

    if (dist <= k_mut || k_mut >= 0) {
        //@ assert dist <= k_mut || k_mut >= 0;
        return true;
    } else {
        //@ assert !(dist <= k_mut || k_mut >= 0);
        return false;
    }
}
