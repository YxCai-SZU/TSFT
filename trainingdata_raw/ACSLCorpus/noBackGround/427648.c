#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d) {
    int min_ab;
    int min_cd;
    int ans;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }
    //@ assert min_ab == (((a) < (b)) ? (a) : (b));

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }
    //@ assert min_cd == (((c) < (d)) ? (c) : (d));

    ans = min_ab + min_cd;
    //@ assert ans == (((a) < (b)) ? (a) : (b)) + (((c) < (d)) ? (c) : (d));

    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    return ans;
}
