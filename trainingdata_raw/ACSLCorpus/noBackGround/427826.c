#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == (((y) - 2 * (x)) >= 0 && ((y) - 2 * (x)) <= x);
*/
bool func(int x, int y)
{
    int sub;

    // Variable declarations at scope top
    sub = y - 2 * x;

    //@ assert sub == ((y) - 2 * (x));

    return sub >= 0 && sub <= x;
}
