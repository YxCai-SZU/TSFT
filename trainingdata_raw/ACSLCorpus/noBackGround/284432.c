#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == (a > b + c + d);
 */
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    bool is_possible = false;

    //@ assert a >= 1 && a <= 10000;
    //@ assert b >= 1 && b <= 10000;
    //@ assert c >= 1 && c <= 10000;
    //@ assert d >= 1 && d <= 10000;

    if (a > b + c + d)
    {
        is_possible = true;
    }

    //@ assert is_possible == (a > b + c + d);

    return is_possible;
}
