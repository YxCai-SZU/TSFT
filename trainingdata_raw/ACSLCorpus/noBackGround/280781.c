#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
        ((a) == (c) && (c) != (b)) ||
        ((b) == (c) && (c) != (a)));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if ((a == b) && (b != c)) {
        result = true;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (c) != (a)));
        return result;
    } else if ((a == c) && (c != b)) {
        result = true;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (c) != (a)));
        return result;
    } else if ((b == c) && (c != a)) {
        result = true;
        //@ assert (((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (c) != (a)));
        return result;
    } else {
        result = false;
        //@ assert !(((a) == (b) && (b) != (c)) ||         ((a) == (c) && (c) != (b)) ||         ((b) == (c) && (c) != (a)));
        return result;
    }
}
