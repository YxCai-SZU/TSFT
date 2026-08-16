#include <limits.h>

/*@
    requires (1 <= (p) <= 100) && (1 <= (q) <= 100) && (1 <= (r) <= 100);
    ensures \result <= p + q;
    ensures \result <= p + r;
    ensures \result <= q + r;
    assigns \nothing;
*/
int func(int p, int q, int r)
{
    // Variable declarations at scope top
    int x;
    int y;

    //@ assert p + q <= 200;
    //@ assert p + r <= 200;
    //@ assert q + r <= 200;

    x = (p + q < p + r) ? (p + q) : (p + r);
    y = (x < q + r) ? x : (q + r);
    return y;
}
