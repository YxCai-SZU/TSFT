#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result = false;

    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    if (a == b + c)
    {
        result = true;
    }

    if (b == a + c)
    {
        result = true;
    }

    if (c == a + b)
    {
        result = true;
    }

    //@ assert result == (a == b + c || b == a + c || c == a + b);

    return result;
}
