#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result == ((b) * (c)) || \result == ((a) * (d)) || 
            \result == ((a) * (c)) || \result == ((b) * (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int max1;
    int max2;
    int ac;
    int bd;
    int ad;
    int bc;
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);

    ac = a * c;
    bd = b * d;
    ad = a * d;
    bc = b * c;

    //@ assert 1 <= ac <= 10000;
    //@ assert 1 <= bd <= 10000;
    //@ assert 1 <= ad <= 10000;
    //@ assert 1 <= bc <= 10000;

    if (ac > bd) {
        max1 = ac;
    } else {
        max1 = bd;
    }

    if (ad > bc) {
        max2 = ad;
    } else {
        max2 = bc;
    }

    if (max1 > max2) {
        result = max1;
    } else {
        result = max2;
    }

    //@ assert result >= 0;
    return result;
}
