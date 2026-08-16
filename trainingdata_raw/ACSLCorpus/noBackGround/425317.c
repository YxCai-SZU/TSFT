#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        3 <= (k) && (k) <= 3);
    ensures \result >= 0 && \result <= 200;
    assigns \nothing;
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

    rst = (rst - a < 0) ? 0 : (rst - a);

    if (b >= rst)
    {
        rst = (rst - b < 0) ? 0 : (rst - b);
    }
    else
    {
        rst = 0;
    }

    res -= rst;

    //@ assert res >= 0 && res <= 200;

    return res;
}
