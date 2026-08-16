#include <stdbool.h>

/*@
    requires 0 <= a && a <= 100;
    requires 0 <= b && b <= 100;
    requires 0 <= c && c <= 100;
    requires a + b + c == 180;
    ensures \result == (a == 90 || b == 90 || c == 90);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool r = false;

    //@ assert a + b + c == 180;

    if (a == 90 || b == 90 || c == 90)
    {
        r = true;
    }

    //@ assert r == (a == 90 || b == 90 || c == 90);

    return r;
}
