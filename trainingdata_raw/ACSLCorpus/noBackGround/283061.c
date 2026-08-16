#include <limits.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        (a) * (b) <= INT_MAX &&
        (a) * (b) >= INT_MIN);
    ensures \result == ((a) * (b));
    ensures 1 <= \result <= 10000;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         (a) * (b) <= INT_MAX &&         (a) * (b) >= INT_MIN);
    //@ assert 1 <= ((a) * (b)) <= 10000;
    
    return a * b;
}
