#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == 1 <==> (((a) == (b) && (a) != (c)) ||
        ((a) != (b) && (a) == (c)) ||
        ((a) != (b) && (b) == (c)));
 */
bool func(int a, int b, int c)
{
    bool ans = false;

    //@ assert a >= 1 && a <= 9;
    //@ assert b >= 1 && b <= 9;
    //@ assert c >= 1 && c <= 9;

    if (a == b) {
        if (a != c) {
            ans = true;
        }
    }
    if (a != b) {
        if (a == c) {
            ans = true;
        }
    }
    if (a != b) {
        if (b == c) {
            ans = true;
        }
    }

    //@ assert ans == 1 <==> (((a) == (b) && (a) != (c)) ||         ((a) != (b) && (a) == (c)) ||         ((a) != (b) && (b) == (c)));
    return ans;
}
