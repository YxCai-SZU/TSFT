#include <stdbool.h>

/*@
    requires ((a) >= 1 && (a) <= 100 &&
        (b) >= 0 && (b) <= (a) * (a));
    ensures \result == ((a) * (a) - (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at scope top
    int result;

    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 0 && b <= a * a;
    //@ assert a * a <= 10000;
    //@ assert a * a - b >= 0;

    result = a * a - b;
    return result;
}
