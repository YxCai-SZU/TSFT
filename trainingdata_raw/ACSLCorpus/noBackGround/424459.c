#include <limits.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        (a) * (b) <= INT_MAX &&
        (a) * (b) >= INT_MIN);
    ensures \result == ((a) * (b));
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b >= 1;
    result = a * b;
    return result;
}
