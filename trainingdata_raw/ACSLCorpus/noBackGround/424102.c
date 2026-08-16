#include <limits.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + b + c + d - 3 * ((a > b ? a : b) + (c > d ? c : d)) - 10;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_cd;
    int ans;

    //@ assert 1 <= a <= 10000 && 1 <= b <= 10000 && 1 <= c <= 10000 && 1 <= d <= 10000;

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    //@ assert (((a) > (b) ==> (max_ab) == (a)) && ((a) <= (b) ==> (max_ab) == (b)));

    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    //@ assert (((c) > (d) ==> (max_cd) == (c)) && ((c) <= (d) ==> (max_cd) == (d)));

    ans = a + b + c + d - 3 * (max_ab + max_cd) - 10;
    //@ assert ans == a + b + c + d - 3 * (max_ab + max_cd) - 10;

    return ans;
}
