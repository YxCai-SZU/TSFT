#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10) && (1 <= (b) <= 10) && (1 <= (c) <= 10);
    ensures \result == (b - a == c - b);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    int a_subtract_b;
    int c_subtract_b;
    bool result;

    a_subtract_b = b - a;
    c_subtract_b = c - b;

    //@ assert a_subtract_b == b - a;
    //@ assert c_subtract_b == c - b;

    if (a_subtract_b == c_subtract_b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a_subtract_b == c_subtract_b);
    return result;
}
