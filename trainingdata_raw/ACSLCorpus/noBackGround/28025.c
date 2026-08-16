#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (x) <= 100);
    ensures \result == (b <= x && a <= x - b);
*/
bool func(int a, int b, int x)
{
    // Variable declarations at top of scope
    bool result;

    if (b > x) {
        result = false;
    } else if (a <= x - b) {
        result = true;
    } else {
        //@ assert b <= x && a > x - b;
        result = false;
    }

    return result;
}
