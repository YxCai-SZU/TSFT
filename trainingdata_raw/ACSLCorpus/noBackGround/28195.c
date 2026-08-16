#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000);
    ensures \result == ((a) * (a) * (a));
    assigns \nothing;
*/
int func(int a)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (-1000 <= (a) <= 1000);
    //@ assert -1000000 <= a * a <= 1000000;
    //@ assert -1000000000 <= ((a) * (a) * (a)) <= 1000000000;

    result = a * a * a;
    //@ assert result == ((a) * (a) * (a));
    return result;
}
