#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 500 &&
        1 <= (b) && (b) <= 500 &&
        1 <= (c) && (c) <= 1000);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 500;
    //@ assert 1 <= b && b <= 500;
    //@ assert 1 <= c && c <= 1000;

    result = (a + b >= c);
    return result;
}
