#include <limits.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    int min_ab;
    int min_cd;

    ans = INT_MAX;

    //@ assert ans == INT_MAX;

    if (a + c < ans) {
        ans = a + c;
    }
    //@ assert ans == a + c || ans == INT_MAX;

    if (a + d < ans) {
        ans = a + d;
    }
    //@ assert ans == a + c || ans == a + d || ans == INT_MAX;

    if (b + c < ans) {
        ans = b + c;
    }
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == INT_MAX;

    if (b + d < ans) {
        ans = b + d;
    }
    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;

    min_ab = a;
    if (b < min_ab) {
        min_ab = b;
    }

    min_cd = c;
    if (d < min_cd) {
        min_cd = d;
    }

    //@ assert ans == a + c || ans == a + d || ans == b + c || ans == b + d;
    return ans;
}
