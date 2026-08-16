#include <stdbool.h>

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 7 || x == 5 || x == 3);
 */
bool func(int x)
{
    int a;
    int b;
    int c;
    bool result;

    a = 7;
    b = 5;
    c = 3;

    //@ assert a == 7 && b == 5 && c == 3;

    result = (x == a) || (x == b) || (x == c);

    //@ assert result == (x == 7 || x == 5 || x == 3);

    return result;
}
