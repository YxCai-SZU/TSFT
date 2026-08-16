#include <stdbool.h>

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == true <==> ((a) + (b) == (c) || (b) + (c) == (a) || (c) + (a) == (b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert a * b <= 100 * 100;
    //@ assert b * c <= 100 * 100;
    //@ assert c * a <= 100 * 100;

    if (a + b == c || b + c == a || c + a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
