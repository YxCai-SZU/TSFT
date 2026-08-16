#include <stdbool.h>

/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (a) && (a) <= 100000 &&
        1 <= (b) && (b) <= 100000);
    ensures \result == (a <= n && n < a + b);
    assigns \nothing;
*/
bool func(long n, long a, long b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 100000;
    //@ assert 1 <= b && b <= 100000;
    //@ assert 1 <= a + b && a + b <= 200000;

    if (a <= n && n < a + b) {
        //@ assert a <= n && n < a + b;
        result = true;
    } else {
        //@ assert !(a <= n && n < a + b);
        result = false;
    }

    return result;
}
