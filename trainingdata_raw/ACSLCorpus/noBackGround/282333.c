#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
 */
bool func(int a, int b, int c)
{
    bool result = false;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if ((a == b && a != c) || (b == c && b != a) || (c == a && c != b))
    {
        result = true;
    }

    //@ assert result == true <==> (((a) == (b) && (b) != (c)) || ((b) == (c) && (c) != (a)) || ((c) == (a) && (a) != (b)));
    return result;
}
