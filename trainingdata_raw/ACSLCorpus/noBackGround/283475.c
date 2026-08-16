#include <limits.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == a + b || \result == b + c || \result == c + d || \result == d + a;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int max_ab;
    int max_bc;
    int max_cd;
    int max_da;
    int result;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert (1 <= (d) <= 100);

    max_ab = (a + b > c + d) ? a + b : c + d;
    max_bc = (b + c > a + d) ? b + c : a + d;
    max_cd = (c + d > a + b) ? c + d : a + b;
    max_da = (d + a > b + c) ? d + a : b + c;

    //@ assert max_ab == a + b || max_ab == c + d;
    //@ assert max_bc == b + c || max_bc == a + d;
    //@ assert max_cd == c + d || max_cd == a + b;
    //@ assert max_da == d + a || max_da == b + c;

    if (max_ab > max_bc)
    {
        if (max_ab > max_cd)
        {
            if (max_ab > max_da)
            {
                result = max_ab;
            }
            else
            {
                result = max_da;
            }
        }
        else
        {
            if (max_cd > max_da)
            {
                result = max_cd;
            }
            else
            {
                result = max_da;
            }
        }
    }
    else
    {
        if (max_bc > max_cd)
        {
            if (max_bc > max_da)
            {
                result = max_bc;
            }
            else
            {
                result = max_da;
            }
        }
        else
        {
            if (max_cd > max_da)
            {
                result = max_cd;
            }
            else
            {
                result = max_da;
            }
        }
    }

    //@ assert result == a + b || result == b + c || result == c + d || result == d + a;
    return result;
}
