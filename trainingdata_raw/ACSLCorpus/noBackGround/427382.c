#include <limits.h>

/*@
    requires (1 <= (r) <= 9);
    requires (1 <= (g) <= 9);
    requires (1 <= (b) <= 9);
    ensures \result == ((r) * 100 + (g) * 10 + (b));
    ensures 111 <= \result <= 999;
*/
int func(int r, int g, int b)
{
    // Variable declarations at top of scope
    int res;

    //@ assert (1 <= (r) <= 9);
    //@ assert (1 <= (g) <= 9);
    //@ assert (1 <= (b) <= 9);
    //@ assert ((r) * 100 + (g) * 10 + (b)) >= 111;
    //@ assert ((r) * 100 + (g) * 10 + (b)) <= 999;

    res = r * 100 + g * 10 + b;
    //@ assert res == ((r) * 100 + (g) * 10 + (b));

    return res;
}
