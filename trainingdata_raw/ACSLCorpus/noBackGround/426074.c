#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a == b + c || b == c + a || c == a + b);
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;

    result = (a == b + c) || (b == c + a) || (c == a + b);

    //@ assert result == (a == b + c || b == c + a || c == a + b);

    return result;
}
