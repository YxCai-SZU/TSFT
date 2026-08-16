#include <limits.h>

/*@
    requires (3 <= (a) <= 20) && (3 <= (b) <= 20);
    ensures \result >= 0;
    ensures \result == a * 2 || \result == a * 2 - 1 || \result == b * 2 - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int ans;

    //@ assert a * 2 >= 0 && a * 2 <= 40;
    //@ assert a * 2 - 1 >= 0 && a * 2 - 1 <= 39;
    //@ assert b * 2 - 1 >= 0 && b * 2 - 1 <= 39;

    if (a == b)
    {
        ans = a * 2;
    }
    else if (a > b)
    {
        ans = a * 2 - 1;
    }
    else
    {
        ans = b * 2 - 1;
    }

    return ans;
}
