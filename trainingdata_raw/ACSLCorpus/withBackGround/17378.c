#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 9;

    predicate condition_holds(integer a, integer b, integer c) =
        (a == b + 1 && c == 1) ||
        (a == b - 1 && c == 9) ||
        (b == c + 1 && a == 1) ||
        (b == c - 1 && a == 9) ||
        (c == a + 1 && b == 1) ||
        (c == a - 1 && b == 9);
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    ensures \result == true <==> condition_holds(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool flag = false;

    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;

    if ((a == b + 1 && c == 1) || (a == b - 1 && c == 9)) {
        flag = true;
    }
    if ((b == c + 1 && a == 1) || (b == c - 1 && a == 9)) {
        flag = true;
    }
    if ((c == a + 1 && b == 1) || (c == a - 1 && b == 9)) {
        flag = true;
    }

    //@ assert flag == true <==> condition_holds(a, b, c);
    return flag;
}
