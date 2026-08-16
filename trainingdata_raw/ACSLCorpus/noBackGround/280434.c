#include <limits.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&
        (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    ensures \result == a + b + c || \result == a + b + d || 
            \result == a + c + d || \result == b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int ab;
    int bc;
    int cd;
    int ac;
    int bd;
    int ad;
    int min_ab_bc;
    int min_ab_bc_ac;
    int min_all;
    int result;

    ab = a + b;
    bc = b + c;
    cd = c + d;
    ac = a + c;
    bd = b + d;
    ad = a + d;

    min_ab_bc = ab;
    //@ assert min_ab_bc == ab || min_ab_bc == bc;
    if (bc < min_ab_bc) {
        min_ab_bc = bc;
    }

    min_ab_bc_ac = min_ab_bc;
    //@ assert min_ab_bc_ac == ab || min_ab_bc_ac == bc || min_ab_bc_ac == ac;
    if (ac < min_ab_bc_ac) {
        min_ab_bc_ac = ac;
    }

    min_all = min_ab_bc_ac;
    //@ assert min_all == ab || min_all == bc || min_all == ac || min_all == bd || min_all == ad;
    if (bd < min_all) {
        min_all = bd;
    }
    if (ad < min_all) {
        min_all = ad;
    }

    if (ab < bc) {
        if (ab < ac) {
            if (ab < ad) {
                result = a + b + d;
            } else {
                result = a + c + d;
            }
        } else if (ac < ad) {
            result = a + c + d;
        } else {
            result = b + c + d;
        }
    } else if (bc < ac) {
        if (bc < ad) {
            result = a + b + d;
        } else {
            result = b + c + d;
        }
    } else if (ac < ad) {
        result = a + b + d;
    } else {
        result = b + c + d;
    }

    //@ assert result == a + b + c || result == a + b + d || result == a + c + d || result == b + c + d;
    return result;
}
