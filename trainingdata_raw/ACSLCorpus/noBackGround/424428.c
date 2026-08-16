#include <stdbool.h>

/*@
    requires 1 <= k <= 100000;
    ensures \result == (k >= 2000 || k % 200 == 0);
    assigns \nothing;
*/
bool func(int k)
{
    int n;
    int m;
    bool result;

    n = k / 200;
    m = k % 200;

    if (n >= 10)
    {
        //@ assert n >= 10;
        result = true;
    }
    else if (m == 0)
    {
        //@ assert m == 0;
        result = true;
    }
    else
    {
        //@ assert n < 10 && m != 0;
        result = false;
    }

    return result;
}
