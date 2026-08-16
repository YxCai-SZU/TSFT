#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (a) != (c)) ||
        ((b) == (c) && (b) != (a)) ||
        ((c) == (a) && (c) != (b)));
 */
bool func(int a, int b, int c)
{
    bool is_in_order = false;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b && a != c)
    {
        is_in_order = true;
    }

    if (b == c && a != b)
    {
        is_in_order = true;
    }

    if (c == a && b != c)
    {
        is_in_order = true;
    }

    //@ assert is_in_order == true <==> (((a) == (b) && (a) != (c)) ||         ((b) == (c) && (b) != (a)) ||         ((c) == (a) && (c) != (b)));

    return is_in_order;
}
