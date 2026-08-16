#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int x;
    int y;
    int ans;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    x = (a < b) ? a : b;
    //@ assert x == (((a) < (b)) ? (a) : (b));

    y = (c < d) ? c : d;
    //@ assert y == (((c) < (d)) ? (c) : (d));

    ans = (x < y) ? x : y;
    //@ assert ans == (((x) < (y)) ? (x) : (y));

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;

    return ans;
}
