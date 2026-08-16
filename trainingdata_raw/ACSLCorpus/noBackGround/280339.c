#include <limits.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == ((a) * (b) - (a) - (b) + 1);
    assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (2 <= (a) && (a) <= 100 &&         2 <= (b) && (b) <= 100);
    
    //@ assert 4 <= a * b && a * b <= 10000;
    //@ assert a * b >= a + b;
    //@ assert a * b - a - b >= 0;

    result = a * b - a - b + 1;
    
    //@ assert result == ((a) * (b) - (a) - (b) + 1);
    return result;
}
