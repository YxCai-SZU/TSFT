#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures \result == (a <= n && n <= b);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;

    if (a <= n && n <= b) {
        result = true;
    } else {
        //@ assert !(a <= n && n <= b);
        result = false;
    }

    return result;
}
