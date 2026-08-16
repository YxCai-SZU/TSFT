#include <stdbool.h>

/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == true <==> (((a) == (b) && (b) != (c)) ||
        ((b) == (c) && (c) != (a)) ||
        ((c) == (a) && (a) != (b)));
    assigns \nothing;
 */
bool func(unsigned long a, unsigned long b, unsigned long c)
{
    bool ret = false;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    if (a == b && b != c) {
        ret = true;
    } else if (b == c && c != a) {
        ret = true;
    } else if (c == a && a != b) {
        ret = true;
    }

    //@ assert ret == true <==> (((a) == (b) && (b) != (c)) ||         ((b) == (c) && (c) != (a)) ||         ((c) == (a) && (a) != (b)));
    return ret;
}
