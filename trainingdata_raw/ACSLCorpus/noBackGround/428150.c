#include <stdbool.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3);
    ensures \result == (a * b * 2 > 10);
    assigns \nothing;
*/
bool func(int a, int b)
{
    // Variable declarations at top of scope
    int c;
    bool result;

    //@ assert (1 <= (a) <= 3 && 1 <= (b) <= 3);
    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;

    c = a * b;
    result = (c * 2) > 10;
    return result;
}
