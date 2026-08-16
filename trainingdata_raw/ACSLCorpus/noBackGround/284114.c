#include <limits.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (x) <= 100 &&
        1 <= (y) <= 100);
    ensures \result >= 0;
    ensures \result == n * y || \result == x + (n - 1) * y;
    assigns \nothing;
*/
int func(int n, int x, int y)
{
    int result;

    //@ assert (1 <= (n) <= 100 &&         1 <= (x) <= 100 &&         1 <= (y) <= 100);

    if (n < x)
    {
        //@ assert 1 <= n <= 100;
        //@ assert 1 <= y <= 100;
        //@ assert n * y <= 100 * 100;
        result = n * y;
    }
    else
    {
        //@ assert 1 <= x <= 100;
        //@ assert 1 <= n <= 100;
        //@ assert 1 <= y <= 100;
        //@ assert x + (n - 1) * y <= 100 + (100 - 1) * 100;
        result = x + (n - 1) * y;
    }

    //@ assert result >= 0;
    //@ assert result == n * y || result == x + (n - 1) * y;
    return result;
}
