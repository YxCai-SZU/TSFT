#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 7;
    predicate sum_ge_k(integer a, integer b, integer c, integer k) = a + b + c >= k;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(c) && valid_range(k);
    requires sum_ge_k(a, b, c, k);
    ensures \result >= -1 * c;
    ensures \result <= 1 * a;
*/
int func(int a, int b, int c, int k)
{
    int res;
    int rst;

    res = 0;
    rst = k;

    if (a >= rst)
    {
        res += rst;
    }
    else
    {
        res += a;
    }

    rst -= a;
    if (rst <= 0)
    {
        //@ assert res >= -1 * c;
        //@ assert res <= 1 * a;
        return res;
    }

    rst -= b;
    if (rst <= 0)
    {
        //@ assert res >= -1 * c;
        //@ assert res <= 1 * a;
        return res;
    }

    res -= rst;
    //@ assert res >= -1 * c;
    //@ assert res <= 1 * a;
    return res;
}
