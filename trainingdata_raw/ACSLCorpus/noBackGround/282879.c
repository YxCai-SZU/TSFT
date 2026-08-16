#include <stdbool.h>

/*@
    requires a >= -100 && b <= 100 && c >= -100 && c <= 100 && a <= b;
    ensures \result == (c >= a && c <= b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool ans = true;

    //@ assert a <= b;
    if (c < a || b < c)
    {
        ans = false;
    }

    //@ assert ans == (c >= a && c <= b);
    return ans;
}
