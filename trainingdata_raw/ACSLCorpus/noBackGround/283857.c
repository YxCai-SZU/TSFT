#include <limits.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 1 && (b) <= 100 &&
        (c) >= 1 && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int m = 0;
    int cnt = 0;

    //@ assert a >= 1 && a <= 100;
    if (a > m) {
        m = a;
    }
    //@ assert m == (a > 0 ? a : 0);
    if (b > m) {
        m = b;
    }
    //@ assert m == (((a) >= (b) && (a) >= (0)) ? (a) :         ((b) >= (a) && (b) >= (0)) ? (b) : (0));
    if (c > m) {
        m = c;
    }
    //@ assert m == (((a) >= (b) && (a) >= (c)) ? (a) :         ((b) >= (a) && (b) >= (c)) ? (b) : (c));

    if (a == m) {
        cnt += 1;
    }
    //@ assert cnt == (a == m ? 1 : 0);
    if (b == m) {
        cnt += 1;
    }
    //@ assert cnt == (a == m ? 1 : 0) + (b == m ? 1 : 0);
    if (c == m) {
        cnt += 1;
    }
    //@ assert cnt == (((a) == (m) ? 1 : 0) +         ((b) == (m) ? 1 : 0) +         ((c) == (m) ? 1 : 0));

    if (cnt == 3) {
        return 1;
    } else if (cnt == 2) {
        return 2;
    } else {
        //@ assert cnt == 0 || cnt == 1;
        return 3;
    }
}
