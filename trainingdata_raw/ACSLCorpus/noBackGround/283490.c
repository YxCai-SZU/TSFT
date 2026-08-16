#include <limits.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        (a) * (b) <= INT_MAX &&
        (a) * (b) >= INT_MIN);
    ensures \result == ((a) * (b));
    assigns \nothing;
*/
int func(int a, int b)
{
    int res;
    
    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         (a) * (b) <= INT_MAX &&         (a) * (b) >= INT_MIN);
    //@ assert ((a) * (b)) <= INT_MAX;
    //@ assert ((a) * (b)) >= INT_MIN;
    //@ assert 1 <= ((a) * (b)) <= 100 * 100;
    
    res = a * b;
    
    //@ assert res == ((a) * (b));
    return res;
}
