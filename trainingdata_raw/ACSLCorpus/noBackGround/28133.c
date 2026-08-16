#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((b) - (a) == (c) - (b));
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    bool result;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    result = (b - a == c - b);
    //@ assert result == true <==> ((b) - (a) == (c) - (b));
    return result;
}
