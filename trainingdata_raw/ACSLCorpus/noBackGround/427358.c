#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= 200;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int diff1;
    int diff2;
    int diff3;

    result = 0;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;

    if (a - b < 0) {
        diff1 = -(a - b);
    } else {
        diff1 = a - b;
    }
    //@ assert diff1 == (((a) - (b) < 0) ? ((b) - (a)) : ((a) - (b)));
    //@ assert ((diff1) >= 0);

    if (b - c < 0) {
        diff2 = -(b - c);
    } else {
        diff2 = b - c;
    }
    //@ assert diff2 == (((b) - (c) < 0) ? ((c) - (b)) : ((b) - (c)));
    //@ assert ((diff2) >= 0);

    if (c - a < 0) {
        diff3 = -(c - a);
    } else {
        diff3 = c - a;
    }
    //@ assert diff3 == (((c) - (a) < 0) ? ((a) - (c)) : ((c) - (a)));
    //@ assert ((diff3) >= 0);

    if (diff1 <= 2 && diff2 <= 2 && diff3 <= 2) {
        result = 0;
        //@ assert result >= 0 && result <= 200;
    } else if ((diff1 > 4 || diff2 > 4 || diff3 > 4) && diff1 >= 0 && diff2 >= 0 && diff3 >= 0) {
        result = 3;
        //@ assert result >= 0 && result <= 200;
    } else {
        result = 2;
        //@ assert result >= 0 && result <= 200;
    }

    //@ assert result >= 0 && result <= 200;
    return result;
}
