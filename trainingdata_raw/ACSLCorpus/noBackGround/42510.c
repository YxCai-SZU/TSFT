#include <limits.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) && (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures \result == ((a) + (b)) || \result == ((b) + (c)) || \result == ((c) + (d)) || \result == ((d) + (a));
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans = INT_MIN;
    int a_b;
    int b_c;
    int c_d;
    int d_a;

    a_b = a + b;
    //@ assert a_b == ((a) + (b));
    if (a_b > ans) {
        ans = a_b;
    }

    b_c = b + c;
    //@ assert b_c == ((b) + (c));
    if (b_c > ans) {
        ans = b_c;
    }

    c_d = c + d;
    //@ assert c_d == ((c) + (d));
    if (c_d > ans) {
        ans = c_d;
    }

    d_a = d + a;
    //@ assert d_a == ((d) + (a));
    if (d_a > ans) {
        ans = d_a;
    }

    //@ assert ans == ((a) + (b)) || ans == ((b) + (c)) || ans == ((c) + (d)) || ans == ((d) + (a));
    return ans;
}
