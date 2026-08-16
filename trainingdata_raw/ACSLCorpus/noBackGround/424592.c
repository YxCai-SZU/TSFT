#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        0 <= (r) && (r) <= 4111);
    ensures \result == r + 100 * (10 - n) || \result == r;
*/
int func(int n, int r)
{
    int max_val;
    int ans;

    //@ assert (1 <= (n) && (n) <= 100 &&         0 <= (r) && (r) <= 4111);

    if (n > 10)
    {
        max_val = n;
    }
    else
    {
        max_val = 10;
    }

    ans = r + 100 * (max_val - n);

    //@ assert ans == r + 100 * (max_val - n);

    if (n > 10)
    {
        //@ assert ans == r + 100 * (n - n);
        //@ assert ans == r;
        return r;
    }
    else
    {
        //@ assert ans == r + 100 * (10 - n);
        return ans;
    }
}
