#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires a != b;
    ensures \result == (c - b == b - a);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int result;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert c - b >= -99 && c - b <= 99;
    //@ assert b - a >= -99 && b - a <= 99;
    result = (c - b == b - a);
    return result;
}
