#include <limits.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&
        (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    ensures \result >= 0;
    ensures \result <= b + c;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int f;
    int s;
    int ans;

    //@ assert ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&         (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);

    f = (a < b) ? a : b;
    s = (c < d) ? c : d;
    ans = (f + s < b + c) ? f + s : b + c;

    //@ assert ans >= 0;
    //@ assert ans <= b + c;

    return ans;
}
