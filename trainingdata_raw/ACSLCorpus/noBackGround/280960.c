#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int m1;
    int m2;
    int res;
    int ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (a > b) {
        m1 = a - b;
    } else {
        m1 = b - a;
    }
    //@ assert m1 == ((a) > (b) ? (a) - (b) : (b) - (a));

    if (c > d) {
        m2 = c - d;
    } else {
        m2 = d - c;
    }
    //@ assert m2 == ((c) > (d) ? (c) - (d) : (d) - (c));

    if (m1 > m2) {
        res = m1;
    } else {
        res = m2;
    }
    //@ assert res == ((m1) > (m2) ? (m1) : (m2));

    if (res < 0) {
        ans = -res;
    } else {
        ans = res;
    }
    //@ assert ans == ((res) < 0 ? -(res) : (res));
    //@ assert ans >= 0;

    return ans;
}
